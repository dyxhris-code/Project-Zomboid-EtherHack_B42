package EtherHack.utils;

import zombie.characters.IsoZombie;
import zombie.core.Core;
import zombie.iso.IsoCamera;
import zombie.iso.IsoUtils;

public class ZombieUtils {
   public static float getScreenPositionX(IsoZombie var0) {
      int var1 = IsoCamera.frameState.playerIndex;
      float var2 = IsoUtils.XToScreen(var0.getX(), var0.getY(), var0.getZ(), 0);
      float var3 = Core.getInstance().getZoom(var1);
      var2 -= IsoCamera.getOffX();
      var2 /= var3;
      return var2;
   }

   public static float getScreenPositionY(IsoZombie var0) {
      int var1 = IsoCamera.frameState.playerIndex;
      float var2 = IsoUtils.YToScreen(var0.getX(), var0.getY(), var0.getZ(), 0);
      float var3 = Core.getInstance().getZoom(var1);
      var2 -= IsoCamera.getOffY();
      var2 -= 128.0F / (2.0F / Core.getTileScale());
      var2 /= var3;
      return var2;
   }
}
