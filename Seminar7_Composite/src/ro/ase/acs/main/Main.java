package ro.ase.acs.main;

import ro.ase.acs.composite.Angajat;
import ro.ase.acs.composite.Departament;
import ro.ase.acs.composite.Manager;

public class Main {

	public static void main(String[] args) {
		Angajat a1 = new Angajat();
		a1.setNume("Vasile");
		a1.setSalariu(4000);
		
		Angajat a2 = new Angajat();
		a2.setNume("Ana");
		a2.setSalariu(5000);
		
		Angajat a3 = new Angajat();
		a3.setNume("Marcel");
		a3.setSalariu(4500);
		
		Manager m1 = new Manager();
		m1.setNume("Florin");
		m1.setSalariu(12000);
		
		Manager m2 = new Manager();
		m2.setNume("Mihaela");
		m2.setSalariu(10000);
		
		m1.adaugaMembru(a1);
		m2.adaugaMembru(a2);
		m2.adaugaMembru(a3);
		m1.adaugaMembru(m2);
		
		System.out.println(m1.afisareDetalii());
		
		m2.stergeMembru(a3);
		System.out.println(m2.afisareDetalii());
		
		System.out.println(m2.cautaMembru("Ana").getSalariu());
		
		Angajat a4 = new Angajat();
		a4.setNume("Mirel");
		a4.setSalariu(3000);
		
		Departament d1 = new Departament();
		d1.setNumeDepartament("Marketing");
		d1.adaugaMembru(a4);
		m1.adaugaMembru(d1);
		
		System.out.println("---------");
		System.out.println(m1.afisareDetalii());
	}
}