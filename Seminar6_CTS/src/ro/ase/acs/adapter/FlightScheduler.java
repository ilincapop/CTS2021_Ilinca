package ro.ase.acs.adapter;

public class FlightScheduler implements FlightAbstractScheduler{
	
	private String[][] places = new String[6][20];
	
	public FlightScheduler() {
		for(int i = 0; i < places.length; i++) {
			for(int j = 0; j < places[i].length; j++) {
				places[i][j] = "O";
			}
		}
	}
	
	public void bookPlace(int column, char place) {
		int row = -1;
		
		switch(place) {
		case 'A':
			row = 0;
			break;
		case 'B':
			row = 1;
			break;	
		case 'C':
			row = 2;
			break;	
		case 'D':
			row = 3;
			break;
		case 'E':
			row = 4;
			break;	
		case 'F':
			row = 5;
			break;	
		}
		
		if(places[row][column].equals("O")) {
			places[row][column] = "X";
		}
		
	}
	
	public void displayPlaces() {
		for(int i = 0; i < places.length; i++) {
			for(int j = 0; j < places[i].length; j++) {
				System.out.print(places[i][j]);
				System.out.print(" ");
			}
			if(i == 2) {
				System.out.println();
			}
			System.out.println();
		}
	}
}
