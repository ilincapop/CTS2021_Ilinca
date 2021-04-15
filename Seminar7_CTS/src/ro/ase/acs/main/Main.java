package ro.ase.acs.main;

import ro.ase.acs.facade.CockpitFacade;

public class Main {

	public static void main(String[] args) {

		CockpitFacade cockpit=new CockpitFacade();
		cockpit.startCar();
		cockpit.stopCar();
		cockpit.emergencyBrake();
	}

}
