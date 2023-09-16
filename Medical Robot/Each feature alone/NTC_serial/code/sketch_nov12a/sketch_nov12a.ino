#define RT0 10000    // resistance of thermistor
#define B 4050      //constant inside the properties of NTC
#define VCC 5
#define R 10000     // the excess resistance

float RT, VR, ln, TX, T0, VRT;

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
  

  Serial.print("Temperature: "); 
 // Serial.print(Tf);
  //Serial.print(" F; ");
  Serial.print(TX);
  Serial.println(" C");   

  delay(500);
}
