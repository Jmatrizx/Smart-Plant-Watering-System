/*
  This project consists of a smart plant watering system, the system reads the dampness value and state of dampness from the soil dampness sensor. The modual for this sensor has a potentiometer that allows the user to change the point at which the sensor 
  will read the state of the plant as wet or dry in the form of a logic 1 or 0. This data is then sent to the Arduino and passed to the LCD to be printed on its screen. If it is found that the dampness value is below the threshold for it being wet 
  and thus the soil is dry, then the servo arm will turn releasing water much like a dam for a short period of time and then close again. The soil sensor is given sufficent time to read the state of the soil to avoid over saturating the plant. 
  The state of the soil and dampness value is also printed on the screen. If the soil is found to be wet then the LCD screen will display this state and the dampness value. The servo will not turn as the soil is sufficently wet. The state of the soil is 
  read at the start of each loop and can be adjusted to preserve power if needed.
  The code in this project that interacts with the serial monitor is used for both testing and monitioring purposes, which is why It has not been commented out.
*/

#include <LiquidCrystal.h>          // LCD Header File 
#include <Servo.h>                  // Servo Header File
const int sensorPin = A0;           // define Analoge output pin as A0 for the Soil Dampness modual, this pin is the output voltage that is related to dampness of the soil
LiquidCrystal lcd(12,11,5,4,3,2);   // define LCD pins
Servo servoMain;                    // Define our Servo

void setup(){            // setup board I/O
//LCD                    
  lcd.begin(16,2);       // define lcd display type

//Moisture Sensor
  Serial.begin(9600);    // open a serial port at 9600 baud  
  pinMode(10,INPUT);     // configure pin 10 as the digital output for the Soil Dampness modual, if the logic is 1 = wet, 0 = dry

//Servo Actuator
  servoMain.attach(6);   // Attaches the servo on digital pin 6 to the servo object 
} 

void loop(){  
//Moisture Sensor
  int sensorVal = analogRead(sensorPin); // Defines Sensor value variable which is equal to the value read via the sensor pin A0
  Serial.print(" dampness value = "); // Prints a string to the serial monitor 
  Serial.println( sensorVal); // Prints the sensor value variable = water content value, to the serial monitor and adds a new line 
  int soilState = digitalRead(10); // Defines variable soilState as the value read at pin 10 to determine if the soil is wet or dry

//LCD 
  lcd.clear();              // The LCD screen is cleared each loop to prevent any overlap or clipping of strings being printed on the LCD screen
  char b[5];                // declaring character array and length of the array
  String str;               // declaring string variable 
  str=String(sensorVal);    // converting integer into a string, so that It can be printed to the LCD screen
  str.toCharArray(b,5);     // passing the value of the string to the character array 
  lcd.setCursor(0,1);       // set the cursor to print at the start of the 2nd line     
  lcd.print("Damp Val:");   // print string on lcd 2nd line     
  
//Conditional statements   
  
  if(soilState == HIGH) {           // If soilState variable is Logic 1 then carry out the folowing actions: 
     Serial.print("Soil is dry");   // print string to the serial monitor
     lcd.setCursor(0,0);            // set to the cursor to print at the start of the 1st line
     lcd.print("Soil is dry!!!");   // print string on the lcd 1st line
     lcd.setCursor(10,1);           // set to cursor to print on 2nd line after the string 'Damp Val'
     lcd.print(b);                  // print String sensorVal variable on lcd 2nd line  
     delay(500);                    // delay/wait 0.5 seconds   
         
//Servo Function
                // The servo has a short delay to give the water enough time to flow into the plant and for the sensor to read the new value, this time period is also short enough so that the plant isn't over saturated with water.
    servoMain.write(45);  // Turn the Servo Left to 45 degrees
    delay(1000);          // wait 1 second
    servoMain.write(0);   // turn Servo Left to 0 degrees
    delay(1000);          // wait 1 second
  }
else {          // This else statement will carry out the following actions if the soils state is not high:
    Serial.print("soil is wet");    // print string to the serial monitor
    lcd.setCursor(0,0);             // set to the cursor to print at the start of the 1st line
    lcd.print("Soil is wet :)");    // print string on the lcd 1st line     
    lcd.setCursor(10,1);            // set to cursor to print on 2nd line after the string 'Damp Val'
    lcd.print(b);                   // print String sensorVal variable on lcd 2nd line  
    delay(500);                     // delay/wait 0.5 seconds 
  } 
  
}  
