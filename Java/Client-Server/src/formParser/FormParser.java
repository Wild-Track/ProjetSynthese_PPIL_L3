package formParser;

import form.Form;

public abstract class FormParser {
	
	public FormParser() {
		super();
	}
	
	public abstract Form findParser(String s);
}
