#include <LiquidCrystal.h>
#include <stlib.h>
#include <PS2Keyboard.h>

/*
* The actual GPS tracking programme
*
*
*/

/* Pin-list
1
2 
3 - Keyboard
4 - Keyboard
5 - LCD
6 - LCD
7 - LCD
8 - LCD
9 - Keyboard
10
11 - LCD
12 - LCD
13 - LED

*/

//Initiation
//LCD
LiquidCrystal lcd(12,11,8,7,6,5);

//Keyboard
PS2Keyboard keyboard;
String keyboardString = String(100);
const int KBDataPin = 9;
const int KBIRQPin =  3;
const int WakeupPin = 4;
// const int RegPin = 2; //Replace with keyboard input
const int LEDPin = 13;

//System
const int MAXMEMBERS = 10; 

int timeSinceReport;
int currentTeam[MAXMEMBERS];

void setup(){
  Serial.begin(9600);
  delay(1000);
  //Setup LCD and print boot-text
  lcd.begin(16,2);
  delay(1000); 
  //Setup GSM
  
  delay(1000);
  //Setup GPS
 
  delay(1000);
  //Set pins and constants
  pinMode(WakeupPin, INPUT);
  
  timeSinceReport = 301;
 // pinMode(RegPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  //Setup keyboard
  keyboard.begin(KBDataPin, KBIRQPin);
  
  //Send SMS to master with boot-verifications stuff
}

void loop(){
    if(WakeupPin == HIGH){     //Check if a team wants to register with the box
      regTeam();
    } else if(timeSinceReport > 300){  //Send a report to master every 5 min
      writeLog();                      //Write log to SD-card
      reportToMaster();                //Send the report
      timeSinceReport = 0;             //Reset timer
    }
}

//Menufunctions
void regTeam(){
  
}

void writeLog(){
  
}

void reportToMaster(){
  
}

//Helpfunctions
