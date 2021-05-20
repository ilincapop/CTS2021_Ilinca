package ro.ase.acs.main;

import ro.ase.acs.observer.Abonat;
import ro.ase.acs.observer.Website;

public class Main {

	public static void main(String[] args) {
		Website website=new Website();
		website.adaugaNewsletter("Articol nou", "Am adaugat un articol nou pe blog");
		Abonat abonat1=new Abonat("popilinca@gmail.com");
		Abonat abonat2=new Abonat("ana@gmail.com");
		Abonat abonat3=new Abonat("bianca@gmail.com");
		
		website.abonare(abonat1);
		website.abonare(abonat2);
		website.abonare(abonat3);
		
		website.trimiteEmail("Articol nou");
		
	}
}
