package ro.ase.acs.observer;

public class Abonat implements Observer{
	private String email;
	private Observabil observabil;
	
	public Abonat(String email) {
		this.email = email;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	@Override
	public void primesteMail(String subiect) {
		System.out.println("Mesaj nou pentru " + email + ": " + subiect);
		try {
			Thread.sleep(2000);
			deschideMail(subiect);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void setObservabil(Observabil observabil) {
		this.observabil=observabil;
		
	}

	@Override
	public void deschideMail(String subiect) {
		if(observabil!=null) {
			System.out.println(observabil.getContinut(subiect));
		}	
	}
}
