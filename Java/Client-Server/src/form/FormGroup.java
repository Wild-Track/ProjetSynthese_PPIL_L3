package form;

import java.awt.Graphics;
import java.util.ArrayList;

public class FormGroup extends Form {
	
	private ArrayList<Form> forms;
	
	public FormGroup(String id) {
		super(id);
		forms = new ArrayList<Form>();
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
	public void draw(Graphics g) {
		for(int i = 0; i < forms.size(); i++) {
			forms.get(i).draw(g);
		}
	}

}
