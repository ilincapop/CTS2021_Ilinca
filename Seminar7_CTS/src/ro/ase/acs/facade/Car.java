package ro.ase.acs.facade;

public class Car {

	private Brake brake;
	private Engine engine;
	private Lights lights;
	
	
	public Car(Brake brake, Engine engine, Lights lights) {
		this.brake = brake;
		this.engine = engine;
		this.lights = lights;
	}
	public Brake getBrake() {
		return brake;
	}
	public void setBrake(Brake brake) {
		this.brake = brake;
	}
	public Engine getEngine() {
		return engine;
	}
	public void setEngine(Engine engine) {
		this.engine = engine;
	}
	public Lights getLights() {
		return lights;
	}
	public void setLights(Lights lights) {
		this.lights = lights;
	}
	
	
}
