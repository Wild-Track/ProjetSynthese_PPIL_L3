package form;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

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
			
			Vecteur2D v1 = new Vecteur2D(30, 30);
			Vecteur2D v2 = new Vecteur2D(100, 100);
			
			Form f1 = new Segment(v1, v2, "red");
//			f1.draw(graphics);
			
			Vecteur2D v3 = new Vecteur2D(100, 100);
			
			Form f2 = new Circle(v3, 50, "blue");
//			f2.draw(graphics);
			
			FormGroup fg = new FormGroup();
			fg.addElement(f1);
			fg.addElement(f2);
			
			fg.draw(graphics);
			
			strategie.show();
			
        } catch (InterruptedException e) {
            // Rien
        }
	}

}
