package form;

import java.awt.Graphics;

public class Circle extends Form {

	private double raduis;
	private String color;
	
	public Circle(String id, Vecteur2D u, double raduis, String color) {
		super(id);
		this.raduis = raduis;
		this.pointList.add(u);
		this.color = color;
	}

	@Override
	public void draw(Graphics g) {
		int largeur = (int) (2 * raduis);
		int hauteur = largeur;
		int[] tab = pointList.get(0).arrondi();
		g.setColor(getColor(color));
		g.fillOval(tab[0], tab[1], largeur, hauteur);
	}
	

	public double getRaduis() {
		return raduis;
	}
	
	public void setRaduis(double raduis) {
		this.raduis = raduis;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	
}
