import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Locale;

public class Interlocutor extends Thread {

    BufferedReader inputFlow;
    PrintStream outputFlow;
    int noClient;

    Interlocutor(Socket socket, int noClient) throws IOException
    {
        this.inputFlow = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.outputFlow = new PrintStream(socket.getOutputStream());

        this.noClient = noClient;



    }

    @Override
    public void run()
    {
        try
        {
            while (!this.isInterrupted())
            {
                String request = this.inputFlow.readLine();
                if (request != null)
                {
                    System.out.println(request + " : " + noClient);

                    this.outputFlow.println(request.toUpperCase());
                }
            }
        }
        catch (IOException e)
        {
            System.out.println("ERROR interlocutor : " + e);
        }
    }
}
