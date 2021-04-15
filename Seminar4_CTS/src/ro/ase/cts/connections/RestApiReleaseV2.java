package ro.ase.cts.connections;

public class RestApiReleaseV2 extends RestServiceV2 {
	public RestApiReleaseV2(String serverUrl) {
		super(serverUrl);
		
		System.out.println("Release server v2");
	}

	@Override
	public void connect() {
		System.out.println("Connected successfully to " + serverUrl);
	}

}
