package ro.ase.acs.facade;

public class CockpitFacade {
	
	private Car car=null;
	
	public CockpitFacade() {
		Engine engine=new Engine();
		Brake brake=new Brake();
		Lights lights=new Lights();
		car=new Car(brake, engine, lights);
	}
	
	public void startCar() {
		car.getBrake().setLevel(1);
		car.getEngine().start();
		car.getEngine().setRpm(1000);
		car.getLights().setHeadLightsOn(true);
	}
	
	public void stopCar() {
		car.getBrake().setLevel(1);
		car.getEngine().setRpm(0);
		car.getLights().setHeadLightsOn(false);
	}
	
	public void emergencyBrake() {
		car.getBrake().setLevel(1);
		car.getEngine().setRpm(0);
		car.getLights().setHazarLightsOn(true);
	}

}
