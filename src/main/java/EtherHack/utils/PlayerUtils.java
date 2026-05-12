package EtherHack.utils;

import zombie.characters.IsoPlayer;
import zombie.characters.IsoZombie;
import zombie.vehicles.BaseVehicle;

public class PlayerUtils {
   public static float getDistanceBetweenPlayerAndZombie(IsoPlayer var0, IsoZombie var1) {
      float var2 = var0.getX() - var1.getX();
      float var3 = var0.getY() - var1.getY();
      return (float)Math.sqrt((double)(var2 * var2 + var3 * var3));
   }

   public static float getDistanceBetweenPlayerAndVehicle(IsoPlayer var0, BaseVehicle var1) {
      float var2 = var0.getX() - var1.getX();
      float var3 = var0.getY() - var1.getY();
      return (float)Math.sqrt((double)(var2 * var2 + var3 * var3));
   }

   public static float getDistanceBetweenPlayers(IsoPlayer var0, IsoPlayer var1) {
      float var2 = var0.getX() - var1.getX();
      float var3 = var0.getY() - var1.getY();
      return (float)Math.sqrt((double)(var2 * var2 + var3 * var3));
   }

   public static float getScreenPositionX(IsoPlayer var0) {
      return var0.getScreenX();
   }

   public static float getScreenPositionY(IsoPlayer var0) {
      return var0.getScreenY();
   }
}
