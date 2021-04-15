package ro.ase.cts.main;

import ro.ase.cts.connections.Configuration;
import ro.ase.cts.connections.RestApiRelease;
import ro.ase.cts.connections.RestService;
import ro.ase.cts.connections.RestServiceV2;
import ro.ase.cts.connections.ServerType;
import ro.ase.cts.connections.SimpleFactory;
import ro.ase.cts.connections.SimpleFactoryV2;

import ro.ase.cts.logger.LoggerSingleton;

public class Program {
	
	public static void main(String[] args) {
//		Logger logger = new Logger();
//		logger.log("Main ended");
		
		LoggerSingleton logger=LoggerSingleton.getInstance();
		logger.log("Main started");
		
		RestApiRelease rest=new RestApiRelease();
		rest.connect();
		
		RestService restService=SimpleFactory.createConnection(ServerType.DEVELOPMENT);
		restService.connect();
		
		RestServiceV2 restV2 = SimpleFactoryV2.createConnection(
				Configuration.readConfiguration(),"https:./.");
		
		restV2.connect();
		
	}

}
