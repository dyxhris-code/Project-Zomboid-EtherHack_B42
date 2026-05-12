package EtherHack.Ether;

import EtherHack.utils.Logger;

public class EtherLogo {
   private static EtherLogo instance;

   private EtherLogo() {
   }

   public void init() {
      Logger.printLog("EtherLogo startup state injection is disabled on Build 42.18.0.");
   }

   public static EtherLogo getInstance() {
      if (instance == null) {
         instance = new EtherLogo();
      }

      return instance;
   }
}
