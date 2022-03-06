package formParser;

import form.Circle;
import form.Form;
import form.Vecteur2D;

public class FormParserCircle extends FormParserCOR {
	
	public FormParserCircle(FormParserCOR suivant) {
		super(suivant);
	}
	
	/**
	 * Regarde si la chaine est un cercle et la transforme si c'est le cas
	 */
	@Override
	public Form Parser(String s) {
		String s1 = s.substring(6);
		String[] split = s1.split(",");
		if(!split[0].equalsIgnoreCase("circle")) {
			return null;
		}
		String id = split[1].substring(3);
		
		int x = Integer.parseInt(split[2].substring(7));
		int y = Integer.parseInt(split[3].substring(0, split[3].length() - 1));
		Vecteur2D u = new Vecteur2D(x, y);
		
		double raduis = Double.parseDouble(split[4].substring(7));
		
		String color = split[5].substring(6);
		
		Form f = new Circle(id, u, raduis, color);
		return f;
	}
	
}
