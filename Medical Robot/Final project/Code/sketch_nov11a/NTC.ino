void NTC() {

  VRT = analogRead(A1);
  VRT= (5.00 / 1023.00)* VRT;
  VR= VCC - VRT;
  RT= VRT / (VR / R);
  
  ln = log(RT/RT0);
  TX = (1 / ((ln/B)+(1/T0)));
  TX = TX - 273.15;
  
  lcd.setCursor(7,0);
  lcd.print("Temp: ");
  lcd.setCursor(7,1);
  lcd.print(TX);   
  lcd.setCursor(12,1);
  lcd.print(" C   ");
  
  //delay(500);            
  //lcd.clear();
}
