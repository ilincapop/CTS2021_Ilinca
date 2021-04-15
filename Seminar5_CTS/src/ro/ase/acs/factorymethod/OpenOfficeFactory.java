package ro.ase.acs.factorymethod;

import ro.ase.acs.simplefactory.Document;
import ro.ase.acs.simplefactory.OpenOfficeSpreadsheet;
import ro.ase.acs.simplefactory.OpenOfficeText;


public class OpenOfficeFactory implements AbstractDocumentFactory{

	@Override
	public Document getDocument(FileType type, String fileName) {
		if(type==FileType.DOCUMENT) {
			OpenOfficeText text=new OpenOfficeText();
			text.setName(fileName);
			return text;
		} else if(type==FileType.SPREADSHEET) {
			OpenOfficeSpreadsheet spreadsheet = new OpenOfficeSpreadsheet();
			spreadsheet.setName(fileName);
			return spreadsheet;
		}
		return null;
	}

}
