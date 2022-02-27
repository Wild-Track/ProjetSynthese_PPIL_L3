import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServeurMajuscule
{
    public static void main(String[] args)
    {
        int servPort = 6969;

        try
        {
            InetAddress addr = InetAddress.getByName("127.0.0.1");
            ServerSocket server = new ServerSocket(servPort, 50, addr);

            System.out.println("serv pret"+ server.toString());

            int noClient = 0;
            while(true)
            {
                Socket socket = server.accept();
                System.out.println("DFGVES : " + noClient);
                noClient++;

                Interlocutor interlocuter = new Interlocutor(socket, noClient);

                interlocuter.start();
            }
        }
        catch (java.io.IOException e)
        {
            System.out.println("SHAAAAAAAAAAAAAAAARK : " + e.toString());
        }
    }
}
