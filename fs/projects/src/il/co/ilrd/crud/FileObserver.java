package il.co.ilrd.crud;

import java.util.Observable;
import java.util.Observer;

public class FileObserver implements Observer {
	String fileToReport;
	GenericCrud<String, Integer> crud;
	
	public FileObserver(String filePath) {
		fileToReport = filePath;
		crud = new CrudFile(filePath);
	}

	@Override
	public void update(Observable monitor, Object line) {
		crud.create((String)line);
	}
}
