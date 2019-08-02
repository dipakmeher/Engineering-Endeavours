import java.net.*;
import java.io.*;
class serverclient extends Thread {
	  Socket serverClient;
	  int clientNo;
	  int squre;
	  serverclient(Socket inSocket,int counter){
	    serverClient = inSocket;
	    clientNo=counter;
	  }
	  public void run(){
	    try{
	      DataInputStream inStream = new DataInputStream(serverClient.getInputStream());
	      DataOutputStream outStream = new DataOutputStream(serverClient.getOutputStream());
	      String clientMessage="", serverMessage="";
	      while(!clientMessage.equals("bye")){
	        int str = inStream.readInt();
			String answer = numberToWord(str);
			outStream.writeUTF(answer);
	      }
	      inStream.close();
	      outStream.close();
	      serverClient.close();
	    }catch(Exception ex){
	      System.out.println(ex);
	    }finally{
	      System.out.println("Client -" + clientNo + " exit!! ");
	    }
	  }
	  private static String numberToWord(int number) {
        // variable to hold string representation of number 
        String words = "";
String unitsArray[] = { "zero", "one", "two", "three", "four", "five", "six", 
                        "seven", "eight", "nine", "ten", "eleven", "twelve",
                        "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
                        "eighteen", "nineteen" };
String tensArray[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty",
                         "sixty", "seventy", "eighty", "ninety" };

if (number == 0) {
	return "zero";
}
// add minus before conversion if the number is less than 0
if (number < 0) { 
           // convert the number to a string 
           String numberStr = "" + number; 
           // remove minus before the number 
           numberStr = numberStr.substring(1); 
           // add minus before the number and convert the rest of number 
           return "minus " + numberToWord(Integer.parseInt(numberStr));
        } 
        // check if number is divisible by 1 million 
        if ((number / 1000000) > 0) {
	words += numberToWord(number / 1000000) + " million ";
	number %= 1000000;
}
// check if number is divisible by 1 thousand
if ((number / 1000) > 0) {
	words += numberToWord(number / 1000) + " thousand ";
	number %= 1000;
}
// check if number is divisible by 1 hundred
if ((number / 100) > 0) {
	words += numberToWord(number / 100) + " hundred ";
	number %= 100;
}

if (number > 0) {
   // check if number is within teens
   if (number < 20) { 
              // fetch the appropriate value from unit array 
              words += unitsArray[number];
           } else { 
              // fetch the appropriate value from tens array 
              words += tensArray[number / 10]; 
              if ((number % 10) > 0) {
		   words += "-" + unitsArray[number % 10];
              }  
       }
}

return words;
}
	}
