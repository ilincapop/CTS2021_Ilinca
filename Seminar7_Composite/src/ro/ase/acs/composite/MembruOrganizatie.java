package ro.ase.acs.composite;

public abstract class MembruOrganizatie {
	public abstract float getSalariu();
	public abstract String getNume();
	
	public abstract void adaugaMembru(MembruOrganizatie membru);
	public abstract void stergeMembru(MembruOrganizatie membru);
	public abstract MembruOrganizatie cautaMembru(String nume);
	
	@Override
	public int hashCode() {
		if(getNume() == null) {
			return 31;
		} else {
			return getNume().hashCode();
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if(obj==null || obj.getClass()!=this.getClass()) {
			return false;
		} else {
			MembruOrganizatie m = (MembruOrganizatie)obj;
			if(this.getNume()==null && m.getNume()!=null) {
				return false;
			} else {
				if(this.getNume()!=null && m.getNume()==null) {
					return false;
				} else {
					if (this.getNume()==null && m.getNume()==null) {
						return true;
					} else {
						return this.getNume().equals(m.getNume());
					}
				}
			}
		}
	}
	
	public abstract String afisareDetalii();
}