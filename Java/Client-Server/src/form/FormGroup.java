package form;

import java.util.ArrayList;

public class FormGroup extends Form {
	
	private ArrayList<Form> forms;
	
	public FormGroup() {
		super();
	}
	
	
	public void addElement(Form f) {
		forms.add(f);
	}
	
	public void removeElementAtIndex(int i) {
		forms.remove(i);
	}
	
	public void removeElement(Form f) {
		forms.remove(f);
	}

	@Override
	public void draw() {
		forms.forEach(n -> draw());
	}

}
