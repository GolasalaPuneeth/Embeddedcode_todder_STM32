/*  Toddler Mat (Vehicles - play and quiz mode)
 *  Latest update is done on 4th May 2022
 *  This code works fine for only one template
 *  That to for wrong answer it won't reply for the first time, it will play sound only after 3 times of wrong inputs
 *
 */
#include <Keypad.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
const byte ROWS = 7; // Seven Horizontal rows
const byte COLS = 6; // Six Vertical columns
bool Alphabet_state = false ;
bool Number_state = false ;
char keys[ROWS][COLS] = {
    {'=', '>', '?', '@', 'A', 'B'},
    {'C', ' ', 'D', 'E', ' ', 'F'},
    {'G', ' ', 'H', 'I', ' ', 'J'},
    {'K', ' ', 'L', 'M', ' ', 'N'},
    {'O', ' ', 'P', 'Q', ' ', 'R'},
    {'S', ' ', 'T', 'U', ' ', 'V'},
    {'W', '[', 'X', 'Y', ']', 'Z'}};
byte led1 = PB7;
byte led2 = PB6;
int count = 0;
int flag = 1;
byte rowPins[ROWS] = {PA4, PA5, PA6, PA7, PB0, PB1, PA1};  // connect to the horizontal pinouts of the keypad
byte colPins[COLS] = {PB10, PB11, PB12, PB13, PB14, PB15}; // connect to the vertical pinouts of the keypad
SoftwareSerial mySoftwareSerial(PA14, PA13);               // RX, TX(for df player)
DFRobotDFPlayerMini myDFPlayer;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void AphalbetQuiz() // Quiz mode
{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    myDFPlayer.play(36);
    delay(3000);
    Serial.println("Quiz Mode Acivated..");
    while (1)
    {
        if (flag == 0)
        {
            flag = 1;
            break;
        }
        int ran = random(61, 91);
        Serial.println(ran);
        myDFPlayer.play(ran);
        delay(2000);
        while (1)
        {
            char key = keypad.getKey();
            int num = key;
            if (num == ran && key != NO_KEY)
            {
                myDFPlayer.play(34);
                Serial.println("TRUE");
                Serial.println(ran);
                Serial.println(num);
                Serial.print("count = ");
                Serial.println(count);
                count = 0;
                delay(5000);
                break;
            }
            if (count == 3 && key != NO_KEY)
            { // completed
                count = 0;
                Serial.println("WRONG ANSWER..");
                myDFPlayer.play(33);
                delay(4900);
                break;
            }
            if (num == 93 && key != NO_KEY)
            { // completed
                count = 0;
                flag = 0;
                Serial.println("inner loop breaked.");
                break;
            }
            if (num == 91 && key != NO_KEY)
            { // completed
                count = 0;
                flag = 0;
                Serial.println("inner loop breaked.");
                break;
            }
            if (key != NO_KEY && count < 2)
            { // incomlete
                Serial.println(key);
                count++;
                myDFPlayer.play(35);
                delay(1900);
            }
            if (count == 2 && key != NO_KEY)
            { // incomplete
                Serial.println("WARNING..");
                count++;
                myDFPlayer.play(ran);
                delay(1500);
            }
        }
    }
}
void NumberQuiz() // Quiz mode
{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    myDFPlayer.play(36);
    delay(3000);
    Serial.println("Quiz Mode Acivated..");
    while (1)
    {
        if (flag == 0)
        {
            flag = 1;
            break;
        }
        int ran = random(61, 91);
        Serial.println(ran);
        myDFPlayer.play(ran * 2);
        delay(2000);
        while (1)
        {
            char key = keypad.getKey();
            int num = key;
            if (num == ran && key != NO_KEY)
            {
                myDFPlayer.play(34);
                Serial.println("TRUE");
                Serial.println(ran);
                Serial.println(num);
                Serial.print("count = ");
                Serial.println(count);
                count = 0;
                delay(5000);
                break;
            }
            if (count == 3 && key != NO_KEY)
            { // completed
                count = 0;
                Serial.println("WRONG ANSWER..");
                myDFPlayer.play(33);
                delay(4900);
                break;
            }
            if (num == 93 && key != NO_KEY)
            { // completed
                count = 0;
                flag = 0;
                Serial.println("inner loop breaked.");
                break;
            }
            if (num == 91 && key != NO_KEY)
            { // completed
                count = 0;
                flag = 0;
                Serial.println("inner loop breaked.");
                break;
            }
            if (key != NO_KEY && count < 2)
            { // incomlete
                Serial.println(key);
                count++;
                myDFPlayer.play(35);
                delay(1900);
            }
            if (count == 2 && key != NO_KEY)
            { // incomplete
                Serial.println("WARNING..");
                count++;
                myDFPlayer.play(ran * 2);
                delay(1500);
            }
        }
    }
}
void Alphabetmode()
{
    Number_state = true;
    Alphabet_state = false;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("ALPHABET MODE");
    myDFPlayer.play(32);
    while (1)
    {
        char key = keypad.getKey();
        if (key == '[' && key != NO_KEY)
        {
            AphalbetQuiz();
            break;
        }
        if (key == ']' && key != NO_KEY)
        {
            break;
        }
        else
        {
            switch (key)
            {
            case '=':
                Serial.println("A");
                myDFPlayer.play(2);
                delay(1500);
                break;
            case '>':
                Serial.println("B");
                myDFPlayer.play(3);
                delay(1500);
                break;
            case '?':
                Serial.println("C");
                myDFPlayer.play(4);
                delay(1500);
                break;
            case '@':
                Serial.println("D");
                myDFPlayer.play(5);
                delay(1500);
                break;
            case 'A':
                Serial.println("E");
                myDFPlayer.play(6);
                delay(1500);
                break;
            case 'B':
                Serial.println("F");
                myDFPlayer.play(7);
                delay(1500);
                break;
            case 'C':
                Serial.println("G");
                myDFPlayer.play(8);
                delay(1500);
                break;
            case 'D':
                Serial.println("H");
                myDFPlayer.play(9);
                delay(1500);
                break;
            case 'E':
                Serial.println("I");
                myDFPlayer.play(10);
                delay(1500);
                break;
            case 'F':
                Serial.println("J");
                myDFPlayer.play(11);
                delay(1500);
                break;
            case 'G':
                Serial.println("K");
                myDFPlayer.play(12);
                delay(1500);
                break;
            case 'H':
                Serial.println("L");
                myDFPlayer.play(13);
                delay(1500);
                break;
            case 'I':
                Serial.println("M");
                myDFPlayer.play(14);
                delay(1500);
                break;
            case 'J':
                Serial.println("N");
                myDFPlayer.play(15);
                delay(1500);
                break;
            case 'K':
                Serial.println("O");
                myDFPlayer.play(16);
                delay(1500);
                break;
            case 'L':
                Serial.println("P");
                myDFPlayer.play(17);
                delay(1500);
                break;
            case 'M':
                Serial.println("Q");
                myDFPlayer.play(18);
                delay(1500);
                break;
            case 'N':
                Serial.println("R");
                myDFPlayer.play(19);
                delay(1500);
                break;
            case 'O':
                Serial.println("S");
                myDFPlayer.play(20);
                delay(1500);
                break;
            case 'P':
                Serial.println("T");
                myDFPlayer.play(21);
                delay(1500);
                break;
            case 'Q':
                Serial.println("U");
                myDFPlayer.play(22);
                delay(1500);
                break;
            case 'R':
                Serial.println("V");
                myDFPlayer.play(23);
                delay(1500);
                break;
            case 'S':
                Serial.println("W");
                myDFPlayer.play(24);
                delay(1500);
                break;
            case 'T':
                Serial.println("X");
                myDFPlayer.play(25);
                delay(1500);
                break;
            case 'U':
                Serial.println("Y");
                myDFPlayer.play(26);
                delay(1500);
                break;
            case 'V':
                Serial.println("Z");
                myDFPlayer.play(27);
                delay(1500);
                break;
            case 'W':
                Serial.println("COMMON SMILE");
                myDFPlayer.play(28);
                delay(1500);
                break;
            case 'X':
                Serial.println("THUMBSUP EMOJI");
                myDFPlayer.play(29);
                delay(1500);
                break;
            case 'Y':
                Serial.println("CRAZY SMILE");
                myDFPlayer.play(30);
                delay(1500);
                break;
            case 'Z':
                Serial.println("SILENT EMOJI");
                myDFPlayer.play(31);
                delay(1500);
                break;
            }
        }
    }
}
void Numbersmode()
{
    Number_state = false;
    Alphabet_state = true;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("NUMBER MODE");
    myDFPlayer.play(91);
    delay(2000);
    while (1)
    {
        char key = keypad.getKey();
        if (key == ']' && key != NO_KEY)
        {
            NumberQuiz();
            break;
        }
        if (key == '[' && key != NO_KEY)
        {
            break;
        }
        else
        {
            switch (key)
            {
            case 'B':
                Serial.println("RED");
                myDFPlayer.play(92);
                delay(1500);
                break;
            case 'A':
                Serial.println("GREEN");
                myDFPlayer.play(93);
                delay(1500);
                break;
            case '@':
                Serial.println("PURPLE");
                myDFPlayer.play(94);
                delay(1500);
                break;
            case '?':
                Serial.println("BLUE");
                myDFPlayer.play(95);
                delay(1500);
                break;
            case '>':
                Serial.println("YELLOW");
                myDFPlayer.play(96);
                delay(1500);
                break;
            case '=':
                Serial.println("PINK");
                myDFPlayer.play(97);
                delay(1500);
                break;
            case 'F':
                Serial.println("WHITE");
                myDFPlayer.play(98);
                delay(1500);
                break;
            case 'E':
                Serial.println("ONE");
                myDFPlayer.play(99);
                delay(1500);
                break;
            case 'D':
                Serial.println("TWO");
                myDFPlayer.play(100);
                delay(1500);
                break;
            case 'C':
                Serial.println("BLACK");
                myDFPlayer.play(101);
                delay(1500);
                break;
            case 'J':
                Serial.println("THREE");
                myDFPlayer.play(102);
                delay(1500);
                break;
            case 'I':
                Serial.println("FOUR");
                myDFPlayer.play(103);
                delay(1500);
                break;
            case 'H':
                Serial.println("FIVE");
                myDFPlayer.play(104);
                delay(1500);
                break;
            case 'G':
                Serial.println("SIX");
                myDFPlayer.play(105);
                delay(1500);
                break;
            case 'N':
                Serial.println("SEVEN");
                myDFPlayer.play(106);
                delay(1500);
                break;
            case 'M':
                Serial.println("EIGHT");
                myDFPlayer.play(107);
                delay(1500);
                break;
            case 'L':
                Serial.println("NINE");
                myDFPlayer.play(108);
                delay(1500);
                break;
            case 'K':
                Serial.println("ZERO");
                myDFPlayer.play(109);
                delay(1500);
                break;
            case 'R':
                Serial.println("SQUARE");
                myDFPlayer.play(110);
                delay(1500);
                break;
            case 'Q':
                Serial.println("HEART");
                myDFPlayer.play(111);
                delay(1500);
                break;
            case 'P':
                Serial.println("DIMOND");
                myDFPlayer.play(112);
                delay(1500);
                break;
            case 'O':
                Serial.println("RECTANGLE");
                myDFPlayer.play(113);
                delay(1500);
                break;
            case 'V':
                Serial.println("TRIANGLE");
                myDFPlayer.play(114);
                delay(1500);
                break;
            case 'U':
                Serial.println("MINUS");
                myDFPlayer.play(115);
                delay(1500);
                break;
            case 'T':
                Serial.println("MULTIPLCATION");
                myDFPlayer.play(116);
                delay(1500);
                break;
            case 'S':
                Serial.println("STAR");
                myDFPlayer.play(117);
                delay(1500);
                break;
            case 'Z':
                Serial.println("CIRCLE");
                myDFPlayer.play(118);
                delay(1500);
                break;
            case 'X':
                Serial.println("EQUAL");
                myDFPlayer.play(119);
                delay(1500);
                break;
            case 'Y':
                Serial.println("PLUS");
                myDFPlayer.play(120);
                delay(1500);
                break;
            case 'W':
                Serial.println("OVEL");
                myDFPlayer.play(121);
                delay(1500);
                break;
            }
        }
    }
}
void setup()
{
    delay(1000);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    mySoftwareSerial.begin(9600);
    Serial.begin(115200);
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
    if (!myDFPlayer.begin(mySoftwareSerial))
    { // Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
    }
    else
    {
        Serial.println(F("DFPlayer Mini online."));
        Serial.println("TODDLER MAT IS READY TO PLAY....");
    }
    myDFPlayer.volume(30);
    myDFPlayer.play(1);
    delay(1500);
}
void loop()
{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
        switch (key)
        {
        case '[':
        if(Alphabet_state){
                  myDFPlayer.play(60);
                  delay(3000);
            }
            Alphabetmode();
            break;
        case ']':
            if(Number_state){
                  myDFPlayer.play(60);
                  delay(3000);
            }
            Numbersmode();
            break;
        }
    }
}
