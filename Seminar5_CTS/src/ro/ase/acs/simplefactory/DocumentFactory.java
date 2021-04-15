package ro.ase.acs.simplefactory;

public class DocumentFactory {
	
	public Document getDocument(DocumentType type, String fileName) {
		if(type==DocumentType.EXCEL) {
			return new ExcelDocument(fileName);
		} else if(type==DocumentType.WORD) {
			return new WordDocument(fileName);
		} else if(type==DocumentType.OPENOFFICE_TEXT) {
			return new OpenOfficeText();
		} else if(type==DocumentType.OPENOFFICE_SPREADSHEET) {
			return new OpenOfficeSpreadsheet();
		} return null;
	}
}
