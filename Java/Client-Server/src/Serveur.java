import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

import form.Form;
import formParser.FormParser;
import formParser.FormParserCOR;
import formParser.FormParserCircle;
import formParser.FormParserCross;
import formParser.FormParserPolygon;
import formParser.FormParserSegment;

public class Serveur {

	public static void main(String[] args) {
		int servPort = 1337;
		try {
            InetAddress addr = InetAddress.getByName("127.0.0.1");
            ServerSocket server = new ServerSocket(servPort, 50, addr);
            
            System.out.println("serv pret"+ server.toString());
            
			FormParser fParser;
			FormParserCOR fSegment = new FormParserSegment(null);
			FormParserCOR fPolygon = new FormParserPolygon(fSegment);
			FormParserCOR fCross = new FormParserCross(fPolygon);
			FormParserCOR fCircle = new FormParserCircle(fCross);
			
			fParser = fCircle;
			
            ArrayList<Form> listForm = new ArrayList<Form>();

			Frame f1AR;
			f1AR = new Frame();

			f1AR.setBounds(0, 0, 800, 800);
			
			f1AR.setVisible(true);
			f1AR.setIgnoreRepaint(true);
			
			int numBuffers = 2;
			f1AR.createBufferStrategy(numBuffers);
	        Thread.sleep(150);
			
			BufferStrategy strategie = f1AR.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();
            
            while(true) {
                Socket socket = server.accept();
                BufferedReader inputFlow = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String request = inputFlow.readLine();
                
                if (request != null) {
                    System.out.println(request);
                    if(request.contains("groupform")) {
                    	request.substring(10);
                    	String split[] = request.split("\\}");
                    	for(int i = 0; i < split.length; i++) {
                    		Form f = fParser.findParser(split[i]);
                        	processing(f, graphics, listForm);
                    	}
                    }
                    else {
                    	Form f = fParser.findParser(request);
                    	processing(f, graphics, listForm);
                    }
        			strategie.show();
                }
            }
            
		} catch (java.io.IOException | InterruptedException e) {
            System.out.println("Erreur : " + e.toString());
        }
	}
	
	public static void processing(Form f, Graphics g, ArrayList<Form> listForm) {
        boolean find = false;
        int position = -1;
        for(int i = 0; i < listForm.size(); i++) {
        	if(listForm.get(i).getId() == f.getId()) {
        		find = true;
        		position = i;
        	}
        }
        if(find) {
        	listForm.set(position, f);
            g.clearRect(0, 0, 800, 800);
        	for(int i = 0; i < listForm.size(); i++) {
        		listForm.get(i).draw(g);
        	}
        }
        else {
        	listForm.add(f);
        	f.draw(g);
        }
	}

}
