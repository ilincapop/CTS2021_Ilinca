package ro.ase.acs.observer;

public interface Observer {
	public void setObservabil(Observabil observabil);
	public void primesteMail(String subiect);
	public void deschideMail(String subiect);
}
