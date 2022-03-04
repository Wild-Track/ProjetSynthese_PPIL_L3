package form;

import java.util.ArrayList;

public abstract class Form {
	
	protected ArrayList<Vecteur2D> pointList;
	
	public Form() {
		super();
	}
	

	public ArrayList<Vecteur2D> getPointList() {
		return pointList;
	}

	public void setPointList(ArrayList<Vecteur2D> pointList) {
		this.pointList = pointList;
	}
	

	public abstract void draw();
	
	public abstract void translation(Vecteur2D u);

	public abstract void rotation(Vecteur2D inv, double teta);
	
	public abstract void homothety(Vecteur2D inv, double ratio);


}
