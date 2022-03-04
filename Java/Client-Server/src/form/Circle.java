package form;

public class Circle extends Form {

	private double raduis;
	private String color;
	
	public Circle(Vecteur2D u, double raduis, String color) {
		super();
		this.raduis = raduis;
		this.color = color;
		this.pointList.add(u);
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
