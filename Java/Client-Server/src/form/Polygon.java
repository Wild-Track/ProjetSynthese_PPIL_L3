package form;

import java.awt.Graphics;
import java.util.ArrayList;

public class Polygon extends Form {
	
	private String color;
	
	public Polygon(String id, ArrayList<Vecteur2D> pointList, String color) {
		super(id);
		for(int i = 0; i < pointList.size(); i++) {
			this.pointList.add(pointList.get(i));
		}
		this.setColor(color);
		
	}

	@Override
	public void draw(Graphics g) {
		int n = pointList.size();
		int xTab[] = new int[n];
		int yTab[] = new int[n];
		for(int i = 0; i < pointList.size(); i++) {
			int temp[] = pointList.get(i).arrondi();
			xTab[i] = temp[0];
			yTab[i] = temp[1];
		}
		g.setColor(getColor(color));
		g.fillPolygon(xTab, yTab, n);
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

}
