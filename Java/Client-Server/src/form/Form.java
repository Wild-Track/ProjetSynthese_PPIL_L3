package form;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Map;

public abstract class Form {
	
	protected String id;
	protected ArrayList<Vecteur2D> pointList;
	protected static Map<String, Color> colorMap = Map.ofEntries(
			Map.entry("black", Color.black),
			Map.entry("blue", Color.blue),
			Map.entry("red", Color.red),
			Map.entry("green", Color.green),
			Map.entry("yellow", Color.yellow),
			Map.entry("cyan", Color.cyan));
	
	public Form(String id) {
		super();
		this.id = id;
		pointList = new ArrayList<Vecteur2D>();
	}
	
	public static Color getColor(String color) {
		return colorMap.get(color.toLowerCase());
	}
	

	public ArrayList<Vecteur2D> getPointList() {
		return pointList;
	}

	public void setPointList(ArrayList<Vecteur2D> pointList) {
		this.pointList = pointList;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public abstract void draw(Graphics g);


}
