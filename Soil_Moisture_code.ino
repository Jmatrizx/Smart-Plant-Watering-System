const int sensorPin = A0;
#include <LiquidCrystal.h> // library file
LiquidCrystal lcd(12,11,5,4,3,2); // define lcb pins
void setup(){  // setup board I/O
//LCD 
  lcd.begin(16,2); // define lcd display type
  //lcd.print("Soil is"); // print text on lcd 1st line
  //lcd.setCursor(0,1); // set to print on 2nd line
  //lcd.print("",); // print text on lcd 2nd line

//Moisture Sensor
  Serial.begin(9600); // open a serial port at 9600 baud  
  pinMode(10,INPUT);  // configure pin 10 as INPUT  
} 

void loop(){  
//Moisture Sensor
  int sensorVal = analogRead(sensorPin); // read the sensor 
  Serial.print("dampness value = "); 
  Serial.println(sensorVal); // print water content value
  int soilState = digitalRead(10); // print if wet or dry

//LCD 
  char b[5];   //declaring character array  
  String str;  //declaring string 
  
  str=String(sensorVal); //converting integer into a string  
  str.toCharArray(b,5); //passing the value of the string to the character array    
  lcd.setCursor(10,1); // set to print on 2nd line
  lcd.print(b); // print text on lcd 2nd line  
  delay(1000); // delay 1 second       

//Conditions  
  if(soilState == HIGH) {
    Serial.print("soil is dry");
     lcd.setCursor(0,0); // set to print on 1st line
     lcd.print("Soil is dry!!!"); // print text on lcd 1st line
     
  }
  else {Serial.print("soil is wet");
  lcd.setCursor(0,0); // set to print on 1st line
  lcd.print("Soil is wet :)"); // print text on lcd 1st line     
  delay(500); // delay 0.5 seconds  
 
  
  lcd.clear();
  }
}  
