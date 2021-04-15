package ro.ase.acs.facade;

public class Engine {
	private int rpm;
	
	public int getRpm() {
		return rpm;
	}
	public void setRpm(int rpm) {
		this.rpm = rpm;
		System.out.println("New rpm " + rpm);
	}
	public void start() {
		System.out.println("The engine has started");
	}

}
