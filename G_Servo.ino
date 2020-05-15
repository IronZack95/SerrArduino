void ServoPos(int posizione_voluta){
        //goes from 0 degrees to 180 degrees
        //Serial.print("Direzione: ");
        
        if(posizione_voluta > ultima_posizione){
                for( int pos = ultima_posizione; pos <= posizione_voluta ; pos += 1) {         // in steps of 1 degree
                        myservo.write(pos);       // tell servo to go to position in variable 'pos'
                        delay(15);                // waits 15ms for the servo to reach the position
                        posizione = pos;
                        //Serial.print("Posizione Servo : " ); Serial.println(pos);     
                }         
        }else if(posizione_voluta < ultima_posizione){
                for ( int pos = ultima_posizione; pos >= posizione_voluta ; pos -= 1) {         // in steps of 1 degree
                        myservo.write(pos);       // tell servo to go to position in variable 'pos'
                        delay(15);                // waits 15ms for the servo to reach the position
                        posizione = pos;
                        //Serial.print("Posizione Servo : " ); Serial.println(pos);     
                }
        } else{};
        posizione = posizione_voluta;
        ultima_posizione = posizione_voluta;
        
    
    return;
  }
