package ro.ase.acs.prototype;

public class Texture implements Cloneable{

	private String name;

	public Texture(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		Texture copyTexture=(Texture)super.clone();
		copyTexture.name=name;
		return copyTexture;
	}
	
	
	
}
