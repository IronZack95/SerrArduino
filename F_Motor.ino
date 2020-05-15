void MotorDir(bool dir){
            //Serial.print("Direzione: ");
      if(dir == true){
            digitalWrite(DIRA,HIGH); //one way
            digitalWrite(DIRB,LOW);
            //Serial.println("avanti");
      }else if(dir == false){
            digitalWrite(DIRA,LOW); // reverse
            digitalWrite(DIRB,HIGH);
            //Serial.println("indietro");
        }
        
        return;
  }


void Motore(){

      //ACCENSIONE  ---------------------------------------------------------------------------------------------
        if((int)temperature > EEPROM.read(Address_TH) && (int)temperature <= EEPROM.read(Address_MAXTEMP)){
                //---PWM 
                if(velocity == 0){                            // Aiuta a partire nel caso parta da fermo
                      for(int ii = 0; ii <= CicliAvvio ; ii++){
                        digitalWrite(ENABLE,LOW); //enable off
                        delay(TimeImpulsiAvvio/2);
                        analogWrite(ENABLE,ImpulsiAvvio); //enable on    
                        delay(TimeImpulsiAvvio/2);
                        direzione = !direzione;
                        MotorDir(direzione);
                        //Serial.println(ii);
                      }  
                  }            
                // A REGIME
                direzione = true;
                MotorDir(direzione);
                
                //calcolo velocità
                velocity = ((MAXVEL - MINVEL)/(EEPROM.read(Address_MAXTEMP) - EEPROM.read(Address_TH)))*pow(((int)temperature - EEPROM.read(Address_TH)),rapporto)   + MINVEL;
                
                //Serial.println(int(velocity));
                analogWrite(ENABLE,(int)velocity); //half speed    // Velocità a regime
               
          }
  
      // SPEGNIMENTO  ---------------------------------------------------------------------------------------------
        if((int)temperature <= EEPROM.read(Address_TH) || (int)temperature> EEPROM.read(Address_MAXTEMP)){
                Serial.println("spengo motore");
                //---PWM 
                velocity = 0;
                digitalWrite(ENABLE,LOW); //enable off
                if((int)temperature> EEPROM.read(Address_MAXTEMP)){
                  Serial.println("MAXTEMP SUPERATA - - - - - ERRORE");
                  return;
                }
        }

        // gestion cionversoni
        velocity_percentuale = (int)velocity*(100./MAXVEL);
    
    return;
  }
