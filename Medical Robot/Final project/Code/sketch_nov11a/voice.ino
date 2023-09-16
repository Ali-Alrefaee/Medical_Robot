void voicep() {
  while(Serial.available())
  {
    delay(10);
    char c=Serial.read();
    voice +=c;
    }
 if (voice.length()>0)
 {
  Serial.println(voice);

   while(voice=="go"){
     digitalWrite(motor1_in_1, HIGH);
     digitalWrite(motor1_in_2, LOW);
     digitalWrite(motor2_in_1, HIGH);
     digitalWrite(motor2_in_2, LOW);
   } 
   if (voice=="back")
   {
      digitalWrite(motor1_in_1, LOW);
      digitalWrite(motor1_in_2, HIGH);
      digitalWrite(motor2_in_1, LOW);
      digitalWrite(motor2_in_2, HIGH);
   }
 
  if (voice=="stop")
  {
    digitalWrite(motor1_in_1, LOW);
    digitalWrite(motor1_in_2, LOW);
    digitalWrite(motor2_in_1, LOW);
    digitalWrite(motor2_in_2, LOW);
   
  }
  

 voice="";
 }}
