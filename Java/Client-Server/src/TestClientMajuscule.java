import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.Socket;

public class TestClientMajuscule
{
    public static void main(String[] args)
    {
        try
        {
            BufferedReader keyboard = new BufferedReader((new InputStreamReader((System.in))));

            System.out.println("Tapez l'adresse du serv");
            String servIP = keyboard.readLine().trim();
            System.out.println(("Tapez le port du serv"));
            int servPort = Integer.parseInt(keyboard.readLine().trim());

            InetAddress servAdress = InetAddress.getByName(servIP);

            Socket socket = new Socket(servAdress, servPort);

            BufferedReader inputFlow = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream outputFlow = new PrintStream(socket.getOutputStream());

            do
            {
                System.out.println("Tapez la requete ou cassez vous");
                String request = keyboard.readLine();

                if (request.equalsIgnoreCase("SHARK"))
                {
                    break;
                }
                else
                {
                    outputFlow.println(request);

                    String response = inputFlow.readLine();
                    System.out.println(response);
                }

            } while(true);

            //socket.close();
        }
        catch ( java.io.IOException e)
        {
            System.out.println("BAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH : " + e.toString());
        }



    }
}
