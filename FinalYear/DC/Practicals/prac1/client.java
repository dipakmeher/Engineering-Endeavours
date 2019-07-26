import java.net.*;
import java.io.*;
public class client {
	public static void main(String[] args) {
		try {
			Socket s = new Socket("localhost",5003);
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			dout.writeUTF("Hello server");
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
