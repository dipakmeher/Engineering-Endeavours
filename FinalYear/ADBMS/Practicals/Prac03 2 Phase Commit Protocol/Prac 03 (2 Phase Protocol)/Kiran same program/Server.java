import java.io.*;
import java.net.*;
import java.util.*;
public class Server
{
boolean closed=false,inputFromAll=false;
List<clientThread> t;
List<String> data;
Server()
{
t = new ArrayList<clientThread>();
data= new ArrayList<String>();
}
public static void main(String args[])
{
Socket clientSocket = null;
ServerSocket serverSocket = null;
int port_number=1111;
Server ser=new Server();
try
{
serverSocket = new ServerSocket(port_number);
}
catch (IOException e)
{
System.out.println(e);
}
while(!ser.closed)
{
try
{
clientSocket = serverSocket.accept();
clientThread th=new clientThread(ser,clientSocket);
(ser.t).add(th);
System.out.println("\nCustomers Connected : "+(ser.t).size());
(ser.data).add("NOT SENT");
th.start();
}
catch (IOException e)
{
}
}

try
{
serverSocket.close();
}
catch(Exception e1)
{
}
}
}
class clientThread extends Thread
{
DataInputStream is = null;
String line;
String destClient="";
String name;
PrintStream os = null;
Socket clientSocket = null;
String clientIdentity;
Server ser;
public clientThread(Server ser,Socket clientSocket)
{
this.clientSocket=clientSocket;
this.ser=ser;
}
public void run()
{
try
{
is = new DataInputStream(clientSocket.getInputStream());
os = new PrintStream(clientSocket.getOutputStream());
os.println("Enter your Application ID :");
name = is.readLine();
clientIdentity=name;
os.println("**** Access Granted ****");
os.println("Please enter COMMIT or ABORT to proceed : ");
for(int i=0; i<(ser.t).size(); i++)
{
if((ser.t).get(i)!=this)
{
((ser.t).get(i)).os.println("**** New Customer "+name+" entered into this Connection ****");
}
}
while (true)
{
line = is.readLine();
if(line.equalsIgnoreCase("ABORT"))
{
System.out.println("\nFrom '"+clientIdentity+"' : ABORT\n\nSince aborted we will not wait for inputs from other Customers.");
System.out.println("\nAborted....");
for(int i=0; i<(ser.t).size(); i++)
{
((ser.t).get(i)).os.println("Aborted Globaly");
((ser.t).get(i)).os.close();
((ser.t).get(i)).is.close();
}
break;
}
if(line.equalsIgnoreCase("COMMIT"))
{
System.out.println("\nFrom '"+clientIdentity+"' : COMMIT");
if((ser.t).contains(this))
{
(ser.data).set((ser.t).indexOf(this), "COMMIT");
for(int j=0;j<(ser.data).size();j++)
{
if(!(((ser.data).get(j)).equalsIgnoreCase("NOT_SENT")))
{
ser.inputFromAll=true;
continue;
}

else
{
ser.inputFromAll=false;
System.out.println("\nWaiting for inputs from other Customers.");
break;
}
}
if(ser.inputFromAll)
{
System.out.println("\n\nCommited....");
for(int i=0; i<(ser.t).size(); i++)
{
((ser.t).get(i)).os.println("Commited Globaly");
((ser.t).get(i)).os.close();
((ser.t).get(i)).is.close();
}
break;
}
}//if t.contains
}//commit
}//while
ser.closed=true;
clientSocket.close();
}
catch(IOException e)
{
};}}
