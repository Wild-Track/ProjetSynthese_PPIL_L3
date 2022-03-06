package form;

import java.awt.Graphics;
import java.util.ArrayList;

public class FormGroup extends Form {
	
	/**
	 * Classe de groupe de forme
	 * Permet de stocker les formes 
	 */
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

	/**
	 * On appel la methode de dessin de la classe de Form
	 */
	@Override
	public void draw(Graphics g) {
		for(int i = 0; i < forms.size(); i++) {
			forms.get(i).draw(g);
		}
	}

}
