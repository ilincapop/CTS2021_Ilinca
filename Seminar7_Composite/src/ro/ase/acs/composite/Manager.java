package ro.ase.acs.composite;

import java.util.HashMap;
import java.util.Map;

public class Manager extends MembruOrganizatie{
	
	private float salariu;
	private String nume;
	private Map<String, MembruOrganizatie> subordonati = new HashMap<>();
	
	public void setSalariu(float salariu) {
		this.salariu = salariu;
	}
	

	public void setNume(String nume) {
		this.nume = nume;
	}


	@Override
	public float getSalariu() {
		return salariu;
	}

	@Override
	public String getNume() {
		return nume;
	}

	@Override
	public void adaugaMembru(MembruOrganizatie membru) {
		subordonati.put(membru.getNume(), membru);
	}

	@Override
	public void stergeMembru(MembruOrganizatie membru) {
		subordonati.remove(membru.getNume());
	}

	@Override
	public MembruOrganizatie cautaMembru(String nume) {
		return subordonati.get(nume);
	}


	@Override
	public String afisareDetalii() {
		StringBuilder deAfisat = new StringBuilder();
		deAfisat.append("Nume: " + this.nume + "\n");
		deAfisat.append("\t");
		for(Map.Entry<String, MembruOrganizatie> it : subordonati.entrySet()) {
			deAfisat.append(it.getValue().afisareDetalii());
		}
		deAfisat.append("\n");
		return deAfisat.toString();
	}

}