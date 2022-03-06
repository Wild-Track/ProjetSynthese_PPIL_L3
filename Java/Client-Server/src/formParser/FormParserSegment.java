package formParser;

import form.Form;
import form.Segment;
import form.Vecteur2D;

public class FormParserSegment extends FormParserCOR {

	public FormParserSegment(FormParserCOR suivant) {
		super(suivant);
	}

	@Override
	public Form Parser(String s) {
		String s1 = s.substring(6);
		String[] split = s1.split(",");
		if(!split[0].equalsIgnoreCase("segment")) {
			return null;
		}
		String id = split[1].substring(3);
		
		int x1 = Integer.parseInt(split[2].substring(7));
		String[] temp = split[3].split("\\)");
		int y1 = Integer.parseInt(temp[0]);
		Vecteur2D u1 = new Vecteur2D(x1, y1);
		
		int x2 = Integer.parseInt(temp[1].substring(1));
		int y2 = Integer.parseInt(split[4].substring(0, split[4].length() - 1));
		Vecteur2D u2 = new Vecteur2D(x2, y2);
		
		String color = split[5].substring(6);
		
		Form f = new Segment(id, u1, u2, color);
		return f;
	}
	
}
