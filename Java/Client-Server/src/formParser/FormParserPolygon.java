package formParser;

import java.util.ArrayList;

import form.Form;
import form.Polygon;
import form.Vecteur2D;

public class FormParserPolygon extends FormParserCOR {

	public FormParserPolygon(FormParserCOR suivant) {
		super(suivant);
	}

	/**
	 * Regarde si la chaine est un polygone et la transforme si c'est le cas
	 */
	@Override
	public Form Parser(String s) {
		String s1 = s.substring(6);
		String[] split = s1.split(",");
		if(!(split[0].equalsIgnoreCase("polygon") || split[0].equalsIgnoreCase("triangle"))) {
			return null;
		}
		String id = split[1].substring(3);
		
		int x = Integer.parseInt(split[2].substring(7));
		int y = 0;
		ArrayList<Vecteur2D> pointList = new ArrayList<Vecteur2D>();
		for(int i = 0; i < split.length - 5; i++) {
			String[] temp = split[i + 3].split("\\)");
			y = Integer.parseInt(temp[0]);
			Vecteur2D u = new Vecteur2D(x, y);
			pointList.add(u);
			x = Integer.parseInt(temp[1].substring(1));
		}
		y = Integer.parseInt(split[split.length - 2].substring(0, split[split.length - 2].length() - 1));
		Vecteur2D v = new Vecteur2D(x, y);
		pointList.add(v);
		
		String color = split[split.length - 1].substring(6);
		
		Form f = new Polygon(id, pointList, color);
		return f;
	}
	

}
