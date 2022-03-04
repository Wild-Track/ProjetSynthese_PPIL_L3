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

	@Override
	public void translation(Vecteur2D u) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void rotation(Vecteur2D inv, double teta) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void homothety(Vecteur2D inv, double ratio) {
		// TODO Auto-generated method stub
		
	}


	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

}
