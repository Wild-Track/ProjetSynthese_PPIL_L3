package form;

import java.awt.Graphics;

public class Segment extends Form {
	
	private String color;
	
	public Segment(Vecteur2D u1, Vecteur2D u2, String color) {
		super();
		this.pointList.add(u1);
		this.pointList.add(u2);
		this.color = color;
	}

	@Override
	public void draw(Graphics g) {
		int[] p1 = this.pointList.get(0).arrondi();
		int[] p2 = this.pointList.get(1).arrondi();
		g.setColor(getColor(color));
		g.drawLine(p1[0], p1[1], p2[0], p2[1]);
	}


	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

}
