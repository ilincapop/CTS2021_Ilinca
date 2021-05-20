package ro.ase.acs.observer;

import java.util.HashMap;

public class Website extends Observabil {
	private HashMap<String, String> newsletters=new HashMap<>();
	
	public void adaugaNewsletter(String subiect, String mesaj) {
		newsletters.put(subiect, mesaj);
	}
	
	public String getContinut(String subiect) {
		return newsletters.get(subiect);
	}
}
