import java.net.*;
import java.io.*;
public class threadclient {
	public static void main(String[] args) {
		try {
			Socket s = new Socket("localhost",5012);
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			DataInputStream din = new DataInputStream(s.getInputStream());
			dout.writeInt(1001); 
			
			String answer = (String)din.readUTF();
			System.out.println("Message= "+answer);
			
			dout.flush();
			dout.close();
			s.close();
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}