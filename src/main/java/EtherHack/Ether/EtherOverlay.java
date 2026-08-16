package EtherHack.Ether;

import EtherHack.annotations.SubscribeLuaEvent;
import EtherHack.utils.EventSubscriber;
import EtherHack.utils.Rendering;
import java.util.ArrayList;
import java.util.Locale;
import zombie.characters.CharacterStat;
import zombie.characters.IsoPlayer;
import zombie.core.Color;
import zombie.inventory.InventoryItem;
import zombie.inventory.types.HandWeapon;
import zombie.iso.IsoWorld;
import zombie.network.GameClient;
import zombie.ui.UIFont;

/**
 * Compact, native-B42 HUD for the information that pztrainer exposed through
 * its ImGui overlay. It deliberately uses the existing game API and renderer.
 */
public final class EtherOverlay {
   private static final float LEFT = 18.0F;
   private static final float TOP = 18.0F;
   private static final float LINE_HEIGHT = 16.0F;

   public EtherOverlay() {
      EventSubscriber.register(this);
   }

   @SubscribeLuaEvent(eventName = "OnPostUIDraw")
   public void draw() {
      EtherMain main = EtherMain.getInstance();
      EtherAPI api = main.etherAPI;
      if (api == null || (!api.isOverlayStatusEnable && !api.isOverlayWeaponInfo && !api.isOverlayEntityCounts)) {
         return;
      }

      IsoPlayer player = IsoPlayer.getInstance();
      if (player == null) {
         drawLine(main, 0, translate(main, "UI_Overlay_Status") + ": " + translate(main, "UI_Overlay_NoPlayer"));
         return;
      }

      int line = 0;
      drawLine(main, line++, translate(main, "UI_Overlay_Title"));
      if (api.isOverlayStatusEnable) {
         float health = player.getBodyDamage() == null ? 0.0F : player.getBodyDamage().getHealth();
         float fatigue = player.getStats() == null ? 0.0F : player.getStats().get(CharacterStat.FATIGUE);
         drawLine(main, line++, translate(main, "UI_Overlay_Health") + formatPercent(health));
         drawLine(main, line++, translate(main, "UI_Overlay_Fatigue") + formatPercent(fatigue));
         drawLine(main, line++, translate(main, "UI_Overlay_Features") + activeFeatureCount(api));
      }
      if (api.isOverlayWeaponInfo) {
         line = drawWeapon(main, player, line);
      }
      if (api.isOverlayEntityCounts) {
         line = drawEntityCounts(main, line);
      }
   }

   private int drawWeapon(EtherMain main, IsoPlayer player, int line) {
      InventoryItem item = player.getPrimaryHandItem();
      String weaponName = item == null ? translate(main, "UI_Overlay_None") : item.getDisplayName();
      drawLine(main, line++, translate(main, "UI_Overlay_Weapon") + weaponName);
      if (item instanceof HandWeapon weapon) {
         drawLine(main, line++, translate(main, "UI_Overlay_Ammo")
                 + weapon.getCurrentAmmoCount() + "/" + weapon.getMaxAmmo());
      }
      return line;
   }

   private int drawEntityCounts(EtherMain main, int line) {
      int players = 0;
      if (GameClient.instance != null && GameClient.instance.getPlayers() != null) {
         players = GameClient.instance.getPlayers().size();
      }
      int zombies = 0;
      int vehicles = 0;
      if (IsoWorld.instance != null && IsoWorld.instance.getCell() != null) {
         ArrayList<?> zombieList = IsoWorld.instance.getCell().getZombieList();
         zombies = zombieList == null ? 0 : zombieList.size();
         if (IsoWorld.instance.getCell().getVehicles() != null) {
            vehicles = IsoWorld.instance.getCell().getVehicles().size();
         }
      }
      drawLine(main, line, translate(main, "UI_Overlay_Entities")
              + String.format(Locale.ROOT, "P:%d  Z:%d  V:%d", players, zombies, vehicles));
      return line + 1;
   }

   private void drawLine(EtherMain main, int line, String text) {
      Color accent = main.etherAPI.mainUIAccentColor;
      float red = accent == null ? 0.22F : accent.r;
      float green = accent == null ? 0.94F : accent.g;
      float blue = accent == null ? 0.49F : accent.b;
      float alpha = line == 0 ? 1.0F : 0.92F;
      float y = TOP + LINE_HEIGHT * line;
      // Draw a one-pixel shadow so diagnostics remain legible over world tiles.
      Rendering.drawText(text, UIFont.Small, LEFT + 1.0F, y + 1.0F,
              0.0F, 0.0F, 0.0F, alpha * 255.0F);
      Rendering.drawText(text, UIFont.Small, LEFT, TOP + LINE_HEIGHT * line,
              red * 255.0F, green * 255.0F, blue * 255.0F, alpha * 255.0F);
   }

   private static String formatPercent(float value) {
      return String.format(Locale.ROOT, "%.0f%%", value);
   }

   private static int activeFeatureCount(EtherAPI api) {
      boolean[] features = {
              api.isEnableGodMode,
              api.isEnableNoclip,
              api.isEnableInvisible,
              api.isEnableNightVision,
              api.isZombieDontAttack,
              api.isNoRecoil,
              api.autoAim.isEnabled(),
              api.isUnlimitedAmmo,
              api.isUnlimitedCarry,
              api.isUnlimitedEndurance,
              api.isUnlimitedCondition
      };
      int active = 0;
      for (boolean enabled : features) {
         if (enabled) {
            active++;
         }
      }
      return active;
   }

   private static String translate(EtherMain main, String key) {
      return main.etherTranslator == null ? key : main.etherTranslator.getTranslate(key);
   }
}
