package ro.ase.acs.adapter;

public class FlightCovidToNonCovidAdapter extends FlightScheduler{
	private FlightCovidScheduler covidScheduler;
	
	public FlightCovidToNonCovidAdapter(FlightCovidScheduler covidScheduler) {
		this.covidScheduler = covidScheduler;
	}
	
	@Override
	public void bookPlace(int column, char place) {
		covidScheduler.bookPlace(column);
	}
	
	@Override
	public void displayPlaces() {
		covidScheduler.printAvailablePlaces();
	}
}

