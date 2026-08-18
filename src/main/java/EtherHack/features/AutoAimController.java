package EtherHack.features;

import EtherHack.Ether.EtherAPI;
import EtherHack.Ether.EtherMain;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import zombie.characters.IsoPlayer;
import zombie.characters.IsoZombie;
import zombie.inventory.InventoryItem;
import zombie.inventory.types.HandWeapon;
import zombie.iso.IsoWorld;
import zombie.iso.Vector2;

public final class AutoAimController {
    static final float MAX_TARGET_DISTANCE = 15.0F;
    static final float MINIMUM_AIM_DOT = 0.70F;
    private static final float MAX_LEVEL_DELTA = 0.25F;

    private boolean enabled;
    private boolean showTarget;
    private String targetPart = "head";
    private IsoZombie lockedTarget;

    public static Vector2 adjustAimVector(IsoPlayer player, Vector2 nativeAimVector) {
        EtherMain main = EtherMain.getInstance();
        EtherAPI api = main.etherAPI;
        return api == null ? nativeAimVector : api.autoAim.adjust(player, nativeAimVector);
    }

    public boolean isEnabled() {
        return this.enabled;
    }

    public void setEnabled(boolean enabled) {
        this.enabled = enabled;
        if (!enabled) {
            this.lockedTarget = null;
        }
    }

    public boolean isShowTarget() {
        return this.showTarget;
    }

    public void setShowTarget(boolean showTarget) {
        this.showTarget = showTarget;
    }

    public String getTargetPart() {
        return this.targetPart;
    }

    public void setTargetPart(String targetPart) {
        if ("torso".equals(targetPart) || "legs".equals(targetPart) || "head".equals(targetPart)) {
            this.targetPart = targetPart;
        }
    }

    public String getLockedTargetName() {
        if (!this.showTarget || this.lockedTarget == null || !this.lockedTarget.isAlive()) {
            return "";
        }
        return String.format(Locale.ROOT, "Zombie (%.1f, %.1f)", this.lockedTarget.getX(), this.lockedTarget.getY());
    }

    Vector2 adjust(IsoPlayer player, Vector2 nativeAimVector) {
        if (!this.enabled
                || player == null
                || nativeAimVector == null
                || player != IsoPlayer.getInstance()
                || player.isDead()
                || !player.isAimControlActive()
                || player.getCurrentSquare() == null
                || IsoWorld.instance == null
                || IsoWorld.instance.getCell() == null) {
            this.lockedTarget = null;
            return nativeAimVector;
        }

        InventoryItem primaryItem = player.getPrimaryHandItem();
        if (!(primaryItem instanceof HandWeapon weapon) || !weapon.isRanged()) {
            this.lockedTarget = null;
            return nativeAimVector;
        }

        float weaponRange = weapon.getMaxRange(player);
        float maximumDistance = Math.min(MAX_TARGET_DISTANCE, weaponRange);
        if (!Float.isFinite(maximumDistance) || maximumDistance <= 0.0F) {
            return nativeAimVector;
        }

        List<AutoAimTargetSelector.Candidate<IsoZombie>> candidates = new ArrayList<>();
        ArrayList<IsoZombie> zombies = IsoWorld.instance.getCell().getZombieList();
        if (zombies == null || zombies.isEmpty()) {
            this.lockedTarget = null;
            return nativeAimVector;
        }

        int playerIndex = player.getIndex();
        if (playerIndex < 0) {
            return nativeAimVector;
        }

        float maximumDistanceSquared = maximumDistance * maximumDistance;
        for (IsoZombie zombie : zombies) {
            if (zombie == null
                    || zombie.getCurrentSquare() == null
                    || playerIndex >= zombie.isVisibleToPlayer.length) {
                continue;
            }

            float deltaX = zombie.getX() - player.getX();
            float deltaY = zombie.getY() - player.getY();
            float deltaZ = zombie.getZ() - player.getZ();
            float distanceSquared = deltaX * deltaX + deltaY * deltaY;
            if (distanceSquared > maximumDistanceSquared || Math.abs(deltaZ) > MAX_LEVEL_DELTA) {
                continue;
            }

            candidates.add(new AutoAimTargetSelector.Candidate<>(
                    zombie,
                    deltaX,
                    deltaY,
                    deltaZ,
                    zombie.isAlive(),
                    zombie.isFakeDead(),
                    zombie.isVisibleToPlayer[player.getIndex()] && player.CanSee(zombie),
                    true));
        }

        var selected = AutoAimTargetSelector.select(
                        candidates,
                        nativeAimVector.x,
                        nativeAimVector.y,
                        maximumDistance,
                        MINIMUM_AIM_DOT);
        if (selected.isEmpty()) {
            this.lockedTarget = null;
            return nativeAimVector;
        }

        this.lockedTarget = selected.get().target();
        return applyDirection(player, nativeAimVector, selected.get());
    }

    private Vector2 applyDirection(
            IsoPlayer player,
            Vector2 nativeAimVector,
            AutoAimTargetSelector.Candidate<IsoZombie> candidate) {
        nativeAimVector.set(candidate.deltaX(), candidate.deltaY());
        nativeAimVector.normalize();
        player.setTargetAndCurrentDirection(nativeAimVector.x, nativeAimVector.y);
        player.setTargetVerticalAimAngle(targetPartAngle());
        return nativeAimVector;
    }

    private float targetPartAngle() {
        return switch (this.targetPart) {
            case "legs" -> 0.22F;
            case "torso" -> 0.0F;
            default -> -0.22F;
        };
    }
}
