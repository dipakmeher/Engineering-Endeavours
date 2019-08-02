import java.net.*;
import java.io.*;
public class mainserver {
  public static void main(String[] args) throws Exception {
    try{
      ServerSocket server=new ServerSocket(5557);
      int counter=0;
      System.out.println("Server Started ....");
      while(true){
        counter++;
        Socket serverClient=server.accept();  //server accept the client connection request
        // System.out.println(" >> " + "Client No:" + counter + " started!");
        serverclient sct = new serverclient(serverClient,counter); //send  the request to a separate thread
        sct.start();
      }
    }catch(Exception e){
      System.out.println(e);
    }
  }
  
}
