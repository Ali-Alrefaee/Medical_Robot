#include <LiquidCrystal.h>

#define RT0 10000    // resistance of thermistor
#define B 4050      //constant inside the properties of NTC
#define VCC 5
#define R 10000     // the excess resistance

float RT, VR, ln, TX, T0, VRT;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin(9600);
T0= 25+273.15;
}

void loop() {

  VRT = analogRead(A0);
  VRT= (5.00 / 1023.00)* VRT;
  VR= VCC - VRT;
  RT= VRT / (VR / R);
  
  ln = log(RT/RT0);
  TX = (1 / ((ln/B)+(1/T0)));
  TX = TX - 273.15;
  

  lcd.print("Temp = ");
  lcd.print(TX);   
  lcd.print(" C");
  
  delay(500);            
  lcd.clear();
}
