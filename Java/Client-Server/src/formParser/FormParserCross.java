package formParser;

import form.Cross;
import form.Form;
import form.Vecteur2D;

public class FormParserCross extends FormParserCOR {

	public FormParserCross(FormParserCOR suivant) {
		super(suivant);
	}

	@Override
	public Form Parser(String s) {
		String s1 = s.substring(6);
		String[] split = s1.split(",");
		if(!split[0].equalsIgnoreCase("cross")) {
			return null;
		}
		String id = split[1].substring(3);
		
		int x1 = Integer.parseInt(split[2].substring(7));
		String[] temp = split[3].split("\\)");
		int y1 = Integer.parseInt(temp[0]);
		Vecteur2D dl = new Vecteur2D(x1, y1);

		int x2 = Integer.parseInt(temp[1].substring(1));
		temp = split[4].split("\\)");
		int y2 = Integer.parseInt(temp[0]);
		Vecteur2D ur = new Vecteur2D(x2, y2);
		
		int x3 = Integer.parseInt(temp[1].substring(1));
		temp = split[5].split("\\)");
		int y3 = Integer.parseInt(temp[0]);
		Vecteur2D dr = new Vecteur2D(x3, y3);
		
		int x4 = Integer.parseInt(temp[1].substring(1));
		int y4 = Integer.parseInt(split[6].substring(0, split[6].length() - 1));
		Vecteur2D ul = new Vecteur2D(x4, y4);

		String color = split[7].substring(6);
		
		Form f = new Cross(id, dl, ur, dr, ul, color);
		return f;
	}

}
