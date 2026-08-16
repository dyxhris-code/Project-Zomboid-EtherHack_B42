package EtherHack.Ether;

import EtherHack.utils.Logger;

public class EtherMain {
   private static EtherMain instance;
   public EtherTranslator etherTranslator;
   public EtherCredits etherCredits;
   public EtherOverlay etherOverlay;
   public EtherLuaManager etherLuaManager;
   public EtherAPI etherAPI;

   private EtherMain() {
   }

   public void init() {
      Logger.printLog("Initializing EtherTrainer...");
      this.etherTranslator = new EtherTranslator();
      this.etherTranslator.loadTranslations();
      this.etherCredits = new EtherCredits();
      this.etherOverlay = new EtherOverlay();
      this.etherAPI = new EtherAPI();
      this.etherAPI.loadAPI();
      this.etherLuaManager = new EtherLuaManager();
      this.etherLuaManager.loadLua();
      Logger.printLog("EtherTrainer initialization completed!");
   }

   public static EtherMain getInstance() {
      if (instance == null) {
         instance = new EtherMain();
      }

      return instance;
   }
}
