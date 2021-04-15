package ro.ase.cts.main;

import ro.ase.cts.logger.LoggerSingleton;
import ro.ase.cts.logger.LoggerSingletonV2;
import ro.ase.cts.logger.LoggerSingletonWithEnum;

public class Gui {

	public static void main(String[] args) {
		
//		Logger logger=new Logger("Logger.txt");
//		logger.log("Gui opened");
		
		LoggerSingleton logger=LoggerSingleton.getInstance("Logger.txt");
		logger.log("Gui opened");
		logger=LoggerSingleton.getInstance();
		logger.log("Gui");
		
		LoggerSingletonWithEnum.INSTANCE.log("Enum!");
		
		LoggerSingletonV2.instance.log("Static");

	}

}
