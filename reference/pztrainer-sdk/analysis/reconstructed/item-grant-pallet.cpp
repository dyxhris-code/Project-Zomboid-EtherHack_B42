// Human-reviewed reconstruction of the disposable pallet item-grant route.
// This is reference pseudocode, not compilable original source.

namespace pztrainer::item_grant {

constexpr int kPalletMarker = 0x505c;
constexpr const char* kCarrierCandidates[] = {
    "Base.Hammer",
    "Base.RollingPin",
    "Base.Saucepan",
    "Base.Fork",
};

struct PendingGrant {
    enum class State {
        idle = 0,
        waiting_for_server_object = 1,
        waiting_for_inventory_write = 2,
    };

    State state;
    std::string requested_item_type;
    std::string carrier_type;
    int amount;
    int carrier_item_id;
    long long next_poll_at;
    long long deadline;
};

bool hasNoWorldEffects(HandWeapon* item) {
    return item->getExplosionRange() <= 0 &&
           item->getExplosionPower() <= 0 &&
           item->getFireRange() <= 0 &&
           item->getFireStartingEnergy() <= 0 &&
           item->getFireStartingChance() <= 0 &&
           item->getSmokeRange() <= 0 &&
           item->getNoiseRange() <= 0 &&
           item->getSensorRange() <= 0;
}

HandWeapon* selectSafePalletCarrier(std::string& selected_type) {
    for (const char* type : kCarrierCandidates) {
        InventoryItem* item = InventoryItemFactory::CreateItem(type);
        HandWeapon* weapon = dynamic_cast<HandWeapon*>(item);
        if (weapon != nullptr && hasNoWorldEffects(weapon)) {
            selected_type = type;
            return weapon;
        }
        releaseLocalReference(item);
    }
    return nullptr;
}

bool sendDisposablePallet(JNIEnv* env, IsoPlayer* player, PendingGrant& pending) {
    HandWeapon* carrier = selectSafePalletCarrier(pending.carrier_type);
    if (carrier == nullptr) {
        return false;
    }

    carrier->setRemoteControlID(kPalletMarker);
    pending.carrier_item_id = carrier->getID();

    IsoGridSquare* square = player->getCurrentSquare();
    AddExplosiveTrapPacket packet;
    packet.set(carrier, player, square);
    packet.sendToServer(PacketType::AddExplosiveTrap);

    pending.state = PendingGrant::State::waiting_for_server_object;
    pending.next_poll_at = now() + 150_ms;
    pending.deadline = now() + 5_s;
    return true;
}

IsoTrap* findReturnedPallet(IsoPlayer* player, PendingGrant& pending) {
    List<IsoObject*>* objects = player->getCurrentSquare()->getObjects();
    for (IsoObject* object : *objects) {
        IsoTrap* trap = dynamic_cast<IsoTrap*>(object);
        if (trap == nullptr) {
            continue;
        }

        HandWeapon* carrier = dynamic_cast<HandWeapon*>(trap->getItem());
        if (carrier == nullptr) {
            continue;
        }

        bool id_matches = pending.carrier_item_id >= 0 &&
                          carrier->getID() == pending.carrier_item_id;
        bool fallback_matches = carrier->getRemoteControlID() == kPalletMarker &&
                                carrier->getFullType() == pending.carrier_type;
        if (id_matches || fallback_matches) {
            return trap;
        }
    }
    return nullptr;
}

bool submitTakeBricksAction(IsoPlayer* player, IsoTrap* pallet,
                            const std::string& item_type, int amount) {
    // Confirmed argument order at 0x18001b338..0x18001b3c6.
    return ISTakeBricks::createNewAndSend(
        player,
        pallet,
        pallet->getSquare(),
        nullptr,
        item_type,
        static_cast<double>(amount));
}

void pollPalletItemGrant(JNIEnv* env, IsoPlayer* player, PendingGrant& pending) {
    if (pending.state == PendingGrant::State::idle || now() < pending.next_poll_at) {
        return;
    }

    if (now() >= pending.deadline) {
        failGrant("server object or inventory write timed out");
        pending = {};
        return;
    }

    if (pending.state == PendingGrant::State::waiting_for_server_object) {
        IsoTrap* pallet = findReturnedPallet(player, pending);
        if (pallet != nullptr && submitTakeBricksAction(
                player, pallet, pending.requested_item_type, pending.amount)) {
            pending.state = PendingGrant::State::waiting_for_inventory_write;
            pending.next_poll_at = now() + 150_ms;
        }
        return;
    }

    if (findReturnedPallet(player, pending) == nullptr) {
        // ISTakeBricks.complete() removed the pallet. The server-side action also
        // created and registered the requested inventory items.
        completeGrant();
        pending = {};
    }
}

}  // namespace pztrainer::item_grant
