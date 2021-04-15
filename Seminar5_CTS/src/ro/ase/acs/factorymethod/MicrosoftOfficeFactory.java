package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.ExcelDocument;
import ro.ase.acs.simplefactory.WordDocument;

public class MicrosoftOfficeFactory implements AbstractDocumentFactory {

	@Override
	public Document getDocument(FileType type, String fileName) {
		if(type==FileType.DOCUMENT) {
			WordDocument wordDoc=new WordDocument(fileName);
			return wordDoc;
		}else if(type==FileType.SPREADSHEET) {
			ExcelDocument excelDoc=new ExcelDocument(fileName);
			return excelDoc;
		}return null;
		
	}
	
}
