package form;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public class Test {

	public static void main(String[] args) {
		try {
			Frame f1AR;
	
			f1AR = new Frame(" Frame tout simple en Active Rendering");
			
			f1AR.setBounds(0, 0, 400, 400);
	
			f1AR.setVisible(true);
			f1AR.setIgnoreRepaint(true);
			
			int numBuffers = 2;
			f1AR.createBufferStrategy(numBuffers);
	        Thread.sleep(150);
			
			BufferStrategy strategie = f1AR.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();
			
//			Vecteur2D v1 = new Vecteur2D(30, 30);
//			Vecteur2D v2 = new Vecteur2D(100, 100);
//			
//			Form f1 = new Segment(v1, v2, "red");
//			f1.draw(graphics);
			
			Vecteur2D v3 = new Vecteur2D(100, 100);
			
			Form f2 = new Circle(v3, 50, "blue");
//			f2.draw(graphics);
			
			FormGroup fg = new FormGroup();
//			fg.addElement(f1);
			fg.addElement(f2);
			
			Vecteur2D v4 = new Vecteur2D(100, 100);
			Vecteur2D v5 = new Vecteur2D(90, 110);		
			Vecteur2D v6 = new Vecteur2D(80, 120);
			Vecteur2D v7 = new Vecteur2D(90, 130);
			Vecteur2D v8 = new Vecteur2D(100, 140);
			Vecteur2D v9 = new Vecteur2D(110, 130);		
			Vecteur2D v10 = new Vecteur2D(120, 120);
			Vecteur2D v11 = new Vecteur2D(115, 105);
			
			ArrayList<Vecteur2D> pointList = new ArrayList<Vecteur2D>(); 
			pointList.add(v4);
			pointList.add(v5);
			pointList.add(v6);
			pointList.add(v7);
			pointList.add(v8);
			pointList.add(v9);
			pointList.add(v10);
			pointList.add(v11);
			
			Form f4 = new Polygon(pointList, "cyan");
			fg.addElement(f4);
//			Form f3 = new Cross(v4, v5, v6, v7, "green");
//			fg.addElement(f3);
			
			fg.draw(graphics);
			
			strategie.show();
			
        } catch (InterruptedException e) {
            // Rien
        }
	}

}
