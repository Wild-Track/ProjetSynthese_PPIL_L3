package form;

public class Segment extends Form {
	
	private String color;
	
	public Segment(Vecteur2D u1, Vecteur2D u2, String color) {
		super();
		this.pointList.add(u1);
		this.pointList.add(u2);
		this.color = color;
	}

	@Override
	public void draw() {
		// TODO Auto-generated method stub
		
	}


	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

}
