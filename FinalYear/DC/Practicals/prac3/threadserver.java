import java.util.*;
import java.io.*;
import java.net.*;
class Threadclass implements Runnable{
	public void run() {
		try {
			ServerSocket ss = new ServerSocket(5012);
			Socket s = ss.accept(); 
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			
			int str = din.readInt();
			String answer = numberToWord(str);
			dout.writeUTF(answer);
			ss.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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
public class threadserver {

	public static void main(String[] args) {
		int n=8,i;
		Thread ts1 = new Thread(new Threadclass());
		ts1.start();
		Thread ts2 = new Thread(new Threadclass());
		ts2.start();
//		for(i=0;i<8;i++){
//			Thread ts = new Thread(new ThreadServer());
//			ts.start();
//		}
	}

}
