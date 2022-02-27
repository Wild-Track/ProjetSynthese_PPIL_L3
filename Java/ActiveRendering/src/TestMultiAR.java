import java.awt.*;
import java.awt.image.BufferStrategy;

public class TestMultiAR
{
    public static void main(String[] args)
    {
        try {
            Frame f1AR;

            f1AR = new Frame(" Frame tout simple en Active Rendering");

            Image icon = Toolkit.getDefaultToolkit().getImage("D:\\Medias\\Image\\Background\\GawrGura.jpg");
            f1AR.setIconImage(icon);

            f1AR.setBounds(30, 60, 400, 400);       // coordonnées en dur : très maladroit

            f1AR.setVisible(true);              // rend le frame visible sur l'écran
            f1AR.setIgnoreRepaint(true);        // désactive l'appel automatique de la fct paint(...) par repaint()


            int numBuffers = 2;
            f1AR.createBufferStrategy(numBuffers);  // crée une strategie de tampon d'image à 1 tampon vidéo
            Thread.sleep(150);                       // au moins 150 ms !!!! pour laisser au système le temps de créer le buffer d'image

            BufferStrategy strategie = f1AR.getBufferStrategy();
            Graphics graphics = strategie.getDrawGraphics();
            // le graphics sert à dessiner sur le tampon


//		    graphics.drawLine(30, 30, 100, 100);    // dessine sur le tampon vidéo. coordonnées en dur : très maladroit

//		    graphics.drawLine(30, 100, 100, 30);    // dessine sur le tampon vidéo

//		    strategie.show();       // place le tampon sur l'écran : la technique utilisée dépend du type de strategie utilisé : blitting, pointeur vidéo, etc.

            Vecteur2D c = new Vecteur2D(200, 200);		// Centre c du cercle
            Vecteur2D u = new Vecteur2D(1, 0);			// Vecteur unitaire
            double R = 50;								// Rayon du cercle autour duquel le cercle tourne
            double r = 10;								// Rayon du cercle
            // Dimension du cercle
            int largeur = (int) (2 * r);
            int hauteur = largeur;

            double teta = Math.PI * 0.01;				// Angle de modification
            Vecteur2D rot = Vecteur2D.polaire(teta);

            int i = 0;
            while(i < 50000)
            {
                Vecteur2D p = c.somme(u.multiplication(R));				// On crée le nouveau vecteur p à partir du centre c et du vecteur unité multiplié au grand rayon R
                u = u.produitComplexe(rot);								// Nouveau vecteur après rotation
                int[] tab = p.arrondi();								// Coordonnées arrondit
                graphics.fillOval(tab[0], tab[1], largeur, hauteur);
                strategie.show();
                graphics.clearRect(30, 30, 400, 400);					// Il faut clear le screen sinon il n'efface pas ce qui a déjà été fait
                Thread.sleep(500);
                i++;
            }

            graphics.dispose();
        } catch (InterruptedException e)
        {
            // il n'y à rien à faire
        }
    }
}
