 /*  Toddler Mat (Vehicles - play and quiz mode)
 *  Latest update is done on 4th May 2022                 
 *  This code works fine for only one template                            
 *  That to for wrong answer it won't reply for the first time, it will play sound only after 3 times of wrong inputs 
 *                            
*/
#include<Keypad.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
const byte ROWS = 7; //Seven Horizontal rows
const byte COLS = 6; //Six Vertical columns
char keys[ROWS][COLS] = {
  {'<','=','>','?','@','A'},
  {'B',' ','C','D',' ','E'},
  {'F',' ','G','H',' ','I'},
  {'J',' ','K','L',' ','M'},
  {'N',' ','O','P',' ','Q'},
  {'R',' ','S','T',' ','U'},
  {'V','W','X','Y','Z','['}
};
int count=0;
int flag=1;
byte rowPins[ROWS] ={PA4,PA5,PA6,PA7,PB0,PB1,PA1}; //connect to the horizontal pinouts of the keypad
byte colPins[COLS] = {PB10 ,PB11,PB12,PB13,PB14,PB15}; //connect to the vertical pinouts of the keypad
SoftwareSerial mySoftwareSerial(PA13,PA14); // RX, TX(for df player)
DFRobotDFPlayerMini myDFPlayer;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void aphalbetQuiz()// Quiz mode
{
   myDFPlayer.play(33);
   delay(3000);
  Serial.println("Quiz Mode Acivated..");
  while(1){
    if(flag==0){
      flag=1;
      break;
    }
  int ran=random(60,86);
  Serial.println(ran);
  myDFPlayer.play(ran);
  delay(2000);
    while(1){
   char key = keypad.getKey();
   int num = key;
   if(num==ran&&key != NO_KEY){  
    myDFPlayer.play(87);        
    Serial.println("TRUE");
    Serial.println(ran);
    Serial.println(num);
    Serial.print("count = ");
    Serial.println(count);
    count=0;
    delay(5000);
    break;
    }   
    if(count<3&&key!=NO_KEY){
     Serial.println(key); 
     count++;
     myDFPlayer.play(88);
     delay(4000); 
    }
     if(count==5&&key!=NO_KEY){
      count=0;
      Serial.println("WRONG ANSWER..");
      myDFPlayer.play(89);
      delay(3000);
      break;
    }
    if(count==3&&key!=NO_KEY){
      Serial.println("WARNING..");
      myDFPlayer.play(ran);
      delay(1250);
    }
    if(num==91&&key!=NO_KEY){
      count=0;
      flag=0;
      Serial.println("inner loop breaked.");
      break;
      }
    }
  }
}
void NumberQuiz()// Quiz mode
{
   myDFPlayer.play(33);
   delay(3000);
  Serial.println("Quiz Mode Acivated..");
  while(1){
    if(flag==0){
      flag=1;
      break;
    }
  int ran=random(60,86);
  Serial.println(ran);
  myDFPlayer.play(ran*2);
  delay(2000);
    while(1){
   char key = keypad.getKey();
   int num = key;
   if(num==ran&&key != NO_KEY){  
    myDFPlayer.play(87);        
    Serial.println("TRUE");
    Serial.println(ran);
    Serial.println(num);
    Serial.print("count = ");
    Serial.println(count);
    count=0;
    delay(5000);
    break;
    }
    if(count<3&&key!=NO_KEY){
     Serial.println(key); 
     count++;
     myDFPlayer.play(88);
     delay(4000);
    }
     if(count==5&&key!=NO_KEY){
      count=0;
      Serial.println("WRONG ANSWER..");
      myDFPlayer.play(89);
      delay(3000);
      break;
    }
    if(count==3&&key!=NO_KEY){
      Serial.println("WARNING..");
      myDFPlayer.play(ran);
      delay(2000);
    }
    if(num==91&&key!=NO_KEY){
      count=0;
      flag=0;
      Serial.println("inner loop breaked.");
      break;
      }
    }
  }
}
void Numbermode(){
  Serial.println("NUMBER MODE");
  myDFPlayer.play(32);
  while(1){
   char  key = keypad.getKey();
   if(key=='W'&&key!=NO_KEY){
      aphalbetQuiz();
      break;
   }
   if(key=='Z'&&key!=NO_KEY){
      break;
   }
  else{
    switch(key){
      case '<':
      Serial.println("A");
      myDFPlayer.play(2);
      break;
      case '=':
      Serial.println("B");
      myDFPlayer.play(3);
      break;
      case '>':
      Serial.println("C");
      myDFPlayer.play(4);
      break;
      case '?':
      Serial.println("D");
      myDFPlayer.play(5);
      break;
      case '@':
      Serial.println("E");
      myDFPlayer.play(6);
      break;
      case 'A':
      Serial.println("F");
      myDFPlayer.play(7);
      break;
      case 'B':
      Serial.println("G");
      myDFPlayer.play(8);
      break;
      case 'C':
      Serial.println("H");
      myDFPlayer.play(9);
      break;
      case 'D':
      Serial.println("I");
      myDFPlayer.play(10);
      break;
      case 'E':
      Serial.println("J");
      myDFPlayer.play(11);
      break;
      case 'F':
      Serial.println("K");
      myDFPlayer.play(12);
      break;
      case 'G':
      Serial.println("L");
       myDFPlayer.play(13);
      break;
      case 'H':
      Serial.println("M");
       myDFPlayer.play(14);
      break;
      case 'I':
      Serial.println("N");
       myDFPlayer.play(15);
      break;
      case 'J':
      Serial.println("O");
      myDFPlayer.play(16);
      break;
      case 'K':
      Serial.println("P");
      myDFPlayer.play(17);
      break;
      case 'L':
      Serial.println("Q");
      myDFPlayer.play(18);
      break;
      case 'M':
      Serial.println("R");
      myDFPlayer.play(19);
      break;
      case 'N':
      Serial.println("S");
      myDFPlayer.play(20);
      break;
      case 'O':
      Serial.println("T");
      myDFPlayer.play(21);
      break;
      case 'P':
      Serial.println("U");
      myDFPlayer.play(22);
      break;
      case 'Q':
      Serial.println("V");
      myDFPlayer.play(23);
      break;
      case 'R':
      Serial.println("W");
      myDFPlayer.play(24);
      break;
      case 'S':
      Serial.println("X");
      myDFPlayer.play(25);
      break;
      case 'T':
      Serial.println("Y");
      myDFPlayer.play(26);
      break;
      case 'U':
      Serial.println("Z");
      myDFPlayer.play(27);
      break;
      case 'V':
      Serial.println("CRAZY SMILE");
      myDFPlayer.play(28);
      break;
      case '[':
      Serial.println("SILENT EMOJI");
      myDFPlayer.play(29);
      break;
      case 'X':
      Serial.println("THUMBS UP");
      myDFPlayer.play(30);
      break;
      case 'Y':
      Serial.println("COMMON SMILE");
      myDFPlayer.play(31);
      break;
    }
    }
   }
  }
void NumberMode(){
  Serial.println("NUMBER MODE");
  myDFPlayer.play();
  delay(2000);
  while(1){
   char  key = keypad.getKey();
   if(key=='W'&&key!=NO_KEY){
      aphalbetQuiz();
      break;
   }
   if(key=='Z'&&key!=NO_KEY){
      break;
   }
  else{
    switch(key){
      case 'A':
      Serial.println("RED");
      myDFPlayer.play(90);
      break;
      case '@':
      Serial.println("GREEN");
      myDFPlayer.play(91);
      break;
      case '?':
      Serial.println("PURPLE");
      myDFPlayer.play(92);
      break;
      case '>':
      Serial.println("BLUE");
      myDFPlayer.play(93);
      break;
      case '=':
      Serial.println("YELLOW");
      myDFPlayer.play(94);
      break;
      case '<':
      Serial.println("PINK");
      myDFPlayer.play(95);
      break;
      case 'E':
      Serial.println("WHITE");
      myDFPlayer.play(96);
      break;
      case 'D':
      Serial.println("H");
      myDFPlayer.play(97);
      break;
      case 'C':
      Serial.println("I");
      myDFPlayer.play(98);
      break;
      case 'B':
      Serial.println("J");
      myDFPlayer.play(99);
      break;
      case 'I':
      Serial.println("K");
      myDFPlayer.play(100);
      break;
      case 'H':
      Serial.println("L");
       myDFPlayer.play(101);
      break;
      case 'G':
      Serial.println("M");
       myDFPlayer.play(102);
      break;
      case 'F':
      Serial.println("N");
       myDFPlayer.play(103);
      break;
      case 'M':
      Serial.println("O");
      myDFPlayer.play(104);
      break;
      case 'L':
      Serial.println("P");
      myDFPlayer.play(105);
      break;
      case 'K':
      Serial.println("Q");
      myDFPlayer.play(106);
      break;
      case 'J':
      Serial.println("R");
      myDFPlayer.play(107);
      break;
      case 'Q':
      Serial.println("S");
      myDFPlayer.play(108);
      break;
      case 'P':
      Serial.println("T");
      myDFPlayer.play(109);
      break;
      case 'O':
      Serial.println("U");
      myDFPlayer.play(110);
      break;
      case 'N':
      Serial.println("V");
      myDFPlayer.play(111);
      break;
      case 'U':
      Serial.println("W");
      myDFPlayer.play(112);
      break;
      case 'T':
      Serial.println("X");
      myDFPlayer.play(113);
      break;
      case 'S':
      Serial.println("Y");
      myDFPlayer.play(114);
      break;
      case 'R':
      Serial.println("Z");
      myDFPlayer.play(115);
      break;
      case '[':
      Serial.println("CRAZY SMILE");
      myDFPlayer.play(116);
      break;
      case 'X':
      Serial.println("SILENT EMOJI");
      myDFPlayer.play(117);
      break;
      case 'Y':
      Serial.println("THUMBS UP");
      myDFPlayer.play(118);
      break;
      case 'V':
      Serial.println("COMMON SMILE");
      myDFPlayer.play(119);
      break;
    }
    }
   }
  }
 
 void setup(){
  delay(1000); 
   mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));  
  if(!myDFPlayer.begin(mySoftwareSerial)){  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    }
  else{
     Serial.println(F("DFPlayer Mini online."));
     Serial.println("TESTING MAT IS READY TO PLAY....");
  }
  myDFPlayer.volume(30); 
    myDFPlayer.play(1);
}
void loop(){
  char key = keypad.getKey();
  if(key!=NO_KEY){
    switch(key){
      case 'W':
      Alphabetmode();
      break;
      case 'Z':
      numbers();
      break;
    }
  }
}
