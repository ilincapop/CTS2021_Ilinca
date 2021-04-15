package ro.ase.acs.main;

import ro.ase.acs.adapter.FlightAbstractScheduler;
import ro.ase.acs.adapter.FlightCovidToNonCovidClassAdapter;
import ro.ase.acs.adapter.FlightScheduler;

public class AdapterMain {

	public static void main(String[] args) {

		FlightAbstractScheduler scheduler = new FlightScheduler();
		//scheduler = new FlightCovidToNonCovidAdapter(new FlightCovidScheduler());
		scheduler = new FlightCovidToNonCovidClassAdapter();
		//existing code
		scheduler.bookPlace(1, 'B');
		scheduler.bookPlace(1, 'C');
		scheduler.displayPlaces();
		
	}

}
