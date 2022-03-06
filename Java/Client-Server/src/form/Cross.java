package form;

import java.awt.Graphics;

public class Cross extends Form {
	
	private String color;
	
	public Cross(Vecteur2D dl, Vecteur2D ur, Vecteur2D dr, Vecteur2D ul, String color) {
		super();
		this.pointList.add(dl);
		this.pointList.add(ur);
		this.pointList.add(dr);
		this.pointList.add(ul);
		this.color = color;
	}

	@Override
	public void draw(Graphics g) {
		Segment s1 = new Segment(pointList.get(0), pointList.get(1), this.color);
		Segment s2 = new Segment(pointList.get(2), pointList.get(3), this.color);
		s1.draw(g);
		s2.draw(g);
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}
	
}