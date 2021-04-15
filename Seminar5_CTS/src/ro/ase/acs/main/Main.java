package ro.ase.acs.main;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.DocumentFactory;
import ro.ase.acs.simplefactory.DocumentType;

public class Main {

	public static void main(String[] args) {
		DocumentFactory documentFactory = new DocumentFactory();
		
		Document document = documentFactory.getDocument(DocumentType.OPENOFFICE_SPREADSHEET, "Doc");
		document.open();
	}
}
