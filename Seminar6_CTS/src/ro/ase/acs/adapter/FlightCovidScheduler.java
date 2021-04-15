package ro.ase.acs.adapter;

public class FlightCovidScheduler implements FlightCovidAbstractScheduler {
	
	private String[][] places = new String[6][20];
	
	public FlightCovidScheduler() {
		for(int i = 0; i < places.length; i++) {
			for(int j = 0; j < places[i].length; j++) {
				places[i][j] = "O";
			}
		}
	}
	
	public void bookPlace(int row) {
		if(places[1][row].equals("O")) {
			places[1][row] = "X";
		} else {
			places[4][row] = "X";
		}
	}
	
	public void printAvailablePlaces() {
		for(int i = 0; i < places.length; i++) {
			for(int j = 0; j < places[i].length; j++) {
				System.out.print(places[i][j]);
				System.out.print(" ");
			}
			
			if(i == 2) {
				System.out.println();
				System.out.print("<-");
			}
			
			System.out.println();
		}
	}
}