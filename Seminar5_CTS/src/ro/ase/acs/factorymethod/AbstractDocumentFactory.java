package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;


public interface AbstractDocumentFactory {
	
	public Document getDocument(FileType type, String fileName);

}
