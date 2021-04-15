package ro.ase.acs.prototype;

public abstract class BuildingBlock implements Cloneable {

	private int x;
	private int y;
	private int z;
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	public int getZ() {
		return z;
	}
	public void setZ(int z) {
		this.z = z;
	}
	
	public abstract void render();
	
	@Override
	public Object clone() throws CloneNotSupportedException {
		BuildingBlock copyBlock=(BuildingBlock)super.clone();
		copyBlock.x=x;
		copyBlock.y=y;
		copyBlock.z=z;
		return copyBlock;
	}
	
}
