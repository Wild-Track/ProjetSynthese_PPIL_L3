package form;

import java.awt.Graphics;

public class Cross extends Form {
	/**
	 * Similaire a la classe Segment 
	 * Attention à l'ordre des parametres les deux premiers sont pour le premier segment et les deux derniers pour le second
	 */
	private String color;
	
	public Cross(String id, Vecteur2D dl, Vecteur2D ur, Vecteur2D dr, Vecteur2D ul, String color) {
		super(id);
		this.pointList.add(dl);
		this.pointList.add(ur);
		this.pointList.add(dr);
		this.pointList.add(ul);
		this.color = color;
	}

	@Override
	public void draw(Graphics g) {
		int[] dl = this.pointList.get(0).arrondi();
		int[] ur = this.pointList.get(1).arrondi();
		
		int[] dr = this.pointList.get(2).arrondi();
		int[] ul = this.pointList.get(3).arrondi();

		g.setColor(getColor(color));

		g.drawLine(dl[0], dl[1], ur[0], ur[1]);
		g.drawLine(dr[0], dr[1], ul[0], ul[1]);
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}
	
}