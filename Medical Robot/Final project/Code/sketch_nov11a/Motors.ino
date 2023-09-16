void Motor() {
if(Serial.available() > 0)
  { 
 
    prevCommand = command;
    command = Serial.read(); 
    Serial.println(command);
    //Change pin mode only if new command is different from previous.   
    if(command!=prevCommand){
     // Serial.println(command); //////////////////////////////////////
      switch(command)
      {
      case 'F':  
      
        digitalWrite(motor1_in_1, HIGH);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, HIGH);
        digitalWrite(motor2_in_2, LOW);
        
        break;
      case 'B':  
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, HIGH);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, HIGH);
        break;
      case 'R':  
       digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, HIGH);
        digitalWrite(motor2_in_1, HIGH);
        digitalWrite(motor2_in_2, LOW); 
        
        break;
      case 'L':
        digitalWrite(motor1_in_1, HIGH);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, HIGH); 
        break;
      case 'S':  
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW);
        break;
      case 'I':  
        digitalWrite(motor1_in_1, HIGH);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW);
        break;  
      case 'J':  
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, HIGH);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, LOW);
        break;
      case 'G':  
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, HIGH);
        digitalWrite(motor2_in_2, LOW);
        break;
      case 'H':
        digitalWrite(motor1_in_1, LOW);
        digitalWrite(motor1_in_2, LOW);
        digitalWrite(motor2_in_1, LOW);
        digitalWrite(motor2_in_2, HIGH); 
        break;
       

         }

      }
    }
  }
