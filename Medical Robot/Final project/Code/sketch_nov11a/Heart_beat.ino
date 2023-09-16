void Heart() {

 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
 /*Serial.println("♥  Ravi Teja Heartbeat using pulses detected ♥ "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. */
    //lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("BPM:");
  lcd.setCursor(0,1);
  lcd.print("     ");
  lcd.setCursor(0,1); 
  lcd.print(myBPM); 
}

  //delay(20);                    // considered best practice in a simple sketch.

}
