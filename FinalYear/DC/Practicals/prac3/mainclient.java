import java.net.*;
import java.io.*;
public class mainclient {
  public static void main(String[] args) throws Exception {
  try{
    Socket socket=new Socket("localhost",5557);
    DataInputStream inStream=new DataInputStream(socket.getInputStream());
    DataOutputStream outStream=new DataOutputStream(socket.getOutputStream());
    Scanner sc = new Scanner(System.in);
    int clientMessage="",serverMessage="";
    while(clientMessage!=0){
      System.out.println("Enter number :");
      clientMessage=sc.nextInt();
      outStream.writeInt(clientMessage); 
      
      String answer = (String)inStream.readUTF();
      System.out.println("Message= "+answer);
      outStream.flush();
    }
    outStream.close();
    outStream.close();
    socket.close();
  }catch(Exception e){
    System.out.println(e);
  }
  }
}
