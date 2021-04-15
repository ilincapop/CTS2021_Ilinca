package ro.ase.acs.adapter;

public class FlightCovidToNonCovidClassAdapter extends FlightCovidScheduler implements FlightAbstractScheduler{

	@Override
	public void bookPlace(int column, char place) {
		super.bookPlace(column);
	}

	@Override
	public void displayPlaces() {
		super.printAvailablePlaces();
	}

}