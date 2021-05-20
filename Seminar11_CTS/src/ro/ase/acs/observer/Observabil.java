package ro.ase.acs.observer;

import java.util.ArrayList;
import java.util.List;

public abstract class Observabil {
	private List<Observer> listaObservers=new ArrayList<>();
	
	public void abonare(Observer observer) {
		listaObservers.add(observer);
		observer.setObservabil(this);
	}
	public void dezabonare(Observer observer) {
		listaObservers.remove(observer);
		observer.setObservabil(null);
	}
	public void trimiteEmail(String subiect) {
		for(Observer observer: listaObservers) {
			observer.primesteMail(subiect);
		}
	}
	
	public abstract String getContinut(String subiect);
}
