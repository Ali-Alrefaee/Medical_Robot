void ultrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
 
  if (distance <=20)
  {
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW);

    delay(500);
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, HIGH);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, HIGH);//back
    delay(2000); 
        digitalWrite(motor1_in_1, HIGH);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW); 
     delay(2000);
     
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW);
        
  }
}
