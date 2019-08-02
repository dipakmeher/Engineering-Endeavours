import java.io.*;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client1 {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) throws UnknownHostException, IOException {
		String line="";
		Socket socket=new Socket("localhost",5557);
		System.out.println("Server is connected...."); 
		DataInputStream in=new DataInputStream(System.in);
		DataOutputStream dout=new DataOutputStream(socket.getOutputStream());
		DataInputStream din=new DataInputStream(socket.getInputStream());
		
		while (!line.equals("Over")) 
        { 
            try
            { 
                line = in.readLine();
                 System.out.println("Enter Number: ");
                dout.writeUTF(line); 
                String out=din.readUTF();
                System.out.println(out);
            } 
            catch(IOException i) 
            { 
                System.out.println(i); 
            } 
        }
		
		
		  din.close(); 
          dout.close(); 
          socket.close(); 
}
	}
