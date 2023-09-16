#include <SoftwareSerial.h>
String voice;
SoftwareSerial BT(0, 1); //TX, RX respetively
int revleft4 = 6;       //REVerse motion of Left motor
int fwdleft5 = 9;       //ForWarD motion of Left motor
int revright6 = 10;      //REVerse motion of Right motor
int fwdright7 = 11;      //ForWarD motion of Right motor


void setup() {

  pinMode(12,OUTPUT);
  Serial.begin(9600); 

 delay(random(500,2000));   // delay for random time
 // Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  
}

void loop() {
  while(Serial.available())
  {
    delay(10);
    char c=Serial.read();
    voice +=c;
    }
 if (voice.length()>0)
 {
  Serial.println(voice);
  if (voice=="go")
  {
   // digitalWrite(12,HIGH);

    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW); 
   
  }
  if (voice=="off")
  {
   // digitalWrite(12,LOW);

    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
   
  }
 voice=""; }

}
