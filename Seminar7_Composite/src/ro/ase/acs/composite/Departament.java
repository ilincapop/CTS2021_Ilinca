package ro.ase.acs.composite;

import java.util.ArrayList;
import java.util.List;

public class Departament extends MembruOrganizatie {
	
	private List<MembruOrganizatie> membruList = new ArrayList<>();
	private String numeDepartament;

	public void setNumeDepartament(String numeDepartament) {
		this.numeDepartament = numeDepartament;
	}

	@Override
	public float getSalariu() {
		float salariuTotal = 0;
		for(MembruOrganizatie a: membruList) {
			salariuTotal+=a.getSalariu();
		}
		return salariuTotal;
	}

	@Override
	public String getNume() {
		return this.numeDepartament;
	}

	@Override
	public void adaugaMembru(MembruOrganizatie membru) {
		membruList.add(membru);
	}

	@Override
	public void stergeMembru(MembruOrganizatie membru) {
		membruList.remove(membru);
	}

	@Override
	public MembruOrganizatie cautaMembru(String nume) {
		for(MembruOrganizatie m : membruList) {
			if(m.getNume().equals(nume)) {
				return m;
			}
		}
		return null;
	}

	@Override
	public String afisareDetalii() {
		StringBuilder sb = new StringBuilder();
		sb.append("Departament: " + this.numeDepartament + "\n");
		sb.append("\t");
		for(MembruOrganizatie m : membruList) {
			sb.append(m.afisareDetalii());
		}
		sb.append("\n");
		return sb.toString();
	}

}