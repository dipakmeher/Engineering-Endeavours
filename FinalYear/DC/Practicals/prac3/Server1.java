import java.io.*; 
import java.text.*; 
import java.util.*; 
import java.net.*; 
  
// Server class 
public class Server1  
{ 
    public static void main(String[] args) throws IOException  
    { 
   
        // server is listening on port 5056 
        ServerSocket ss = new ServerSocket(5557); 
          
        // running infinite loop for getting 
        // client request 
        while (true)  
        { 
            Socket s = null; 
              
            try 
            { 
                // socket object to receive incoming client requests 
                s = ss.accept(); 
                  
                System.out.println("A new client is connected : " + s); 
                  
                // obtaining input and out streams 
                DataInputStream dis = new DataInputStream(s.getInputStream()); 
                DataOutputStream dos = new DataOutputStream(s.getOutputStream()); 
                  
                System.out.println("Assigning new thread for this client"); 
  
                // create a new thread object 
                Thread t = new ClientHandler(s, dis, dos); 
  
                // Invoking the start() method 
                t.start(); 
                  
            } 
            catch (Exception e){ 
                s.close(); 
                e.printStackTrace(); 
            } 
        } 
    } 
} 
  
// ClientHandler class 
class ClientHandler extends Thread  
{ 
    
    final DataInputStream dis; 
    final DataOutputStream dos; 
    final Socket s; 
      
  
    // Constructor 
    public ClientHandler(Socket s, DataInputStream dis, DataOutputStream dos)  
    { 
        this.s = s; 
        this.dis = dis; 
        this.dos = dos; 
    } 
  
    @Override
    public void run()  
    { 
     String line="";
        while (!line.equals("Over")) 
         { 
             try
             { 
            	 StringBuffer sb=new StringBuffer();
            	 sb.append("");
                 line = dis.readUTF(); 
                 System.out.println("Enter Number: ");
                 int n=Integer.parseInt(line);
                 int rem,sum=0;
                 while(n>0) {
                	 rem=n%10;
                	 sum=sum*10+rem;
                	 n/=10;
                 }
                 
                 while(sum>0) {
                	 rem=sum%10;
                	 switch(rem) {
                	 case 1:
                		 sb.append("one ");
                		 break;
                	 case 2:
                		 sb.append("two ");
                		 break;
                	 case 3:
                		 sb.append("three ");
                		 break;
                	 case 4:
                		 sb.append("four ");
                		 break;
                	 case 5:
                		 sb.append("five ");
                		 break;
                	 case 6:
                		 sb.append("six ");
                		 break;
                	 case 7:
                		 sb.append("seven ");
                		 break;
                	 case 8:
                		 sb.append("eight ");
                		 break;
                	 case 9:
                		 sb.append("nine ");
                		 break;
                	 case 0:
                		 sb.append("zero ");
                		 break;
                		 
                	 }
                	 sum=sum/10;
                 }
                 
                 dos.writeUTF(sb.toString());
             } 
             catch(IOException i) 
             { 
                 System.out.println(i); 
             } 
         }
          
        try
        { 
            // closing resources 
            this.dis.close(); 
            this.dos.close(); 
              
        }catch(IOException e){ 
            e.printStackTrace(); 
        } 
    } 
} 
