package ro.ase.acs.facade;

public class Lights {
	
	private boolean headLightsOn;
	private boolean hazarLightsOn;
	private boolean brakeLightsOn;
	private boolean signalLeftOn;
	private boolean signalRightOn;
	public boolean isHeadLightsOn() {
		return headLightsOn;
	}
	public void setHeadLightsOn(boolean headLightsOn) {
		this.headLightsOn = headLightsOn;
		if(headLightsOn) {
			System.out.println("Headlights on");
		}else {
			System.out.println("Headlights off");
		}
	}
	public boolean isHazarLightsOn() {
		return hazarLightsOn;
	}
	public void setHazarLightsOn(boolean hazarLightsOn) {
		this.hazarLightsOn = hazarLightsOn;
		if(hazarLightsOn) {
			System.out.println("Hazard lights on");
		}else {
			System.out.println("Hazard lights off");
		}
	}
	public boolean isBrakeLightsOn() {
		return brakeLightsOn;
	}
	public void setBrakeLightsOn(boolean brakeLightsOn) {
		this.brakeLightsOn = brakeLightsOn;
	}
	public boolean isSignalLeftOn() {
		return signalLeftOn;
	}
	public void setSignalLeftOn(boolean signalLeftOn) {
		this.signalLeftOn = signalLeftOn;
	}
	public boolean isSignalRightOn() {
		return signalRightOn;
	}
	public void setSignalRightOn(boolean signalRightOn) {
		this.signalRightOn = signalRightOn;
	}
	
	
	

}
