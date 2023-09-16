#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);

//#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#define RT0 10000    // resistance of thermistor
#define B 4050      //constant inside the properties of NTC
#define VCC 5
#define R 10000     // the excess resistance
#define motor1_in_1 6
#define motor1_in_2 9

#define motor2_in_1 10
#define motor2_in_2 11

#define trigPin  7      // trig pin of HC-SR04
# define echoPin 8     // Echo pin of HC-SR04


const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"
String voice;
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
//const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
 float RT, VR, ln, TX, T0, VRT;                              
char command = 'S';
char prevCommand = 'A';
int velocity=0;
long duration, distance;
long time1,time2,time3,time4,time5;

void setup() {

Serial.begin(9600);  //Set the baud rate to that of your Bluetooth module.
  

 lcd.begin(16, 2);
delay(random(500,2000)); 
 pinMode(motor1_in_1 , OUTPUT);
   pinMode(motor1_in_2 , OUTPUT);
   pinMode(motor2_in_1 , OUTPUT);
   pinMode(motor2_in_2 , OUTPUT);
    pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT); 
   
 pulseSensor.analogInput(PulseWire);   
  //pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

T0= 25+273.15;

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    //Serial.println("Ravi Teja Creative Catchers Pulse detector !!");  //This prints one time at Arduino power-up,  or on Arduino reset.  
    lcd.clear();
    lcd.print("  WELCOME DEAR"); // BEATS PER MINUTE
    delay(1000);
    lcd.clear();
    lcd.print("  We are here ");
    lcd.setCursor(0,1);
    lcd.print("    for you");
    delay(2000);
    lcd.clear();
  }

time1=millis();
}

void loop() {

if(millis()-time1>=1000)
{
  time1=millis();
  NTC();
}else if(millis()-time2>=1000)
{
  time2=millis();
  Heart();
}else if(millis()-time3>=20)
{
  time3=millis();
  Motor();
}
 else if (millis()-time4>=800)
  {
    time4=millis();
    voicep();
  }
  else if (millis()-time5>=600)
  {
     time5=millis();
    ultrasonic();
   
  }
  
}
