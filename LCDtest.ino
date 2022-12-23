#include <LiquidCrystal.h> // library file
LiquidCrystal lcd(12,11,5,4,3,2); // define lcb pins


void setup(){ 
  lcd.begin(16,2); // define lcd display type
  lcd.print("hi there"); // print text on lcd 1st line
  lcd.setCursor(0,1); // set to print on 2nd line
  lcd.print("i am counting"); // print text on lcd 2nd line
}

void loop(){ 
  int N;
  char b[2];   //declaring character array  
  String str;  //declaring string 
 
  for(N=0;N<=9;N++){   
  str=String(N); //converting integer into a string  
  str.toCharArray(b,2); //passing the value of the string to the character array    
  lcd.setCursor(15,1); // set to print on 2nd line
  lcd.print(b); // print text on lcd 2nd line  
  delay(1000);       
  }  
}
