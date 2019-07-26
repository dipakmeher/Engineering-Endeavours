import java.util.*;
import java.io.*;
import java.net.*;
public class server {
	public static void main(String[] args) {
		
			
			try {
				ServerSocket ss = new ServerSocket(5003);
				Socket s = ss.accept();
				DataInputStream dis = new DataInputStream(s.getInputStream());
				String str = (String)dis.readUTF();
				System.out.println("Message= "+str);
				ss.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}

}
