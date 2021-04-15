package ro.ase.cts.connections;

public class RestApiDevelopment implements RestService {
	
	public RestApiDevelopment () {
		System.out.println("Development server");
		
	}

	@Override
	public void connect() {
		System.out.println("Conectare cu succes!");		
	}

	
}
