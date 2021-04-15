package ro.ase.cts.connections;

public class RestApiRelease implements RestService {
	
	
	public RestApiRelease() {
		System.out.println("Release server");
	}
	
	public void connect() {
		System.out.println("Conectare cu succes");
	}

}
