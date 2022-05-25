void ServoPos(int posizione_voluta){
        //goes from 0 degrees to 180 degrees
        //Serial.print("Direzione: ");
        bool direct = true;
        
        if(posizione_voluta > ultima_posizione){
                for( int pos = ultima_posizione; pos <= posizione_voluta ; pos += 1) {         // in steps of 1 degree
                        //myservo.write(pos);       // tell servo to go to position in variable 'pos'
                        delay(15);                // waits 15ms for the servo to reach the position
                        posizione = pos;
                        //Serial.print("Posizione Servo : " ); Serial.println(pos);     
                } 
                direct = true;        
                                
        }else if(posizione_voluta < ultima_posizione){
                for ( int pos = ultima_posizione; pos >= posizione_voluta ; pos -= 1) {         // in steps of 1 degree
                        //myservo.write(pos);       // tell servo to go to position in variable 'pos'
                        delay(15);                // waits 15ms for the servo to reach the position
                        posizione = pos;
                        //Serial.print("Posizione Servo : " ); Serial.println(pos);     
                }
                direct = false;
        } else{};

        // assestamento servo
        for(int ii = 0; ii < CicliFermo ; ii++){
                        if(direct == true){
                              posizione_voluta = posizione_voluta - Gradi;
                        }else{
                              posizione_voluta = posizione_voluta + Gradi;
                        }
                        direct = !direct;
                        //myservo.write(posizione_voluta);
                        delay(15);                // waits 15ms for the servo to reach the position
                        posizione = posizione_voluta;
                }

        
        posizione = posizione_voluta;
        ultima_posizione = posizione_voluta;
        
    
    return;
  }

void ServoLight(){
  
    // comunicazione servo provvisoria
    float posizion = light_percentuale*(MAXSERVO/100);
    if((int)posizion != posizione) {
        ServoPos((int)posizion);
    }
    
    return;
  }


void GestioneIrrigazione(){
  
    Serial.println(F("GESTIONE IRRIGAZIONE"));
    int unixtime =  (int)dt.minute + 60*(int)dt.hour;
    //Serial.println(unixtime);
    int starttimeM =  (int)EEPROM.read(Address_MATNSTRT_M) + 60*(int)EEPROM.read(Address_MATNSTRT_H);
    int stoptimeM = starttimeM + (int)EEPROM.read(Address_DURIRRIG_M) + 60*(int)EEPROM.read(Address_DURIRRIG_H);
    //Serial.println(starttimeM);  Serial.println(stoptimeM);
    
    int starttimeS =  (int)EEPROM.read(Address_SERASTRT_M) + 60*(int)EEPROM.read(Address_SERASTRT_H);
    int stoptimeS = starttimeS + (int)EEPROM.read(Address_DURIRRIG_M) + 60*(int)EEPROM.read(Address_DURIRRIG_H);
    //Serial.println(starttimeS);  Serial.println(stoptimeS);
  
      if(IrrigMod != 0){ 
          IrrigMod = ModalitaIrrigazione(unixtime, starttimeM, stoptimeM, starttimeS, stoptimeS);
          Serial.print("Modalità: ");  Serial.println(IrrigMod);
      }
      if(IrrigMod == 1){
          IrrigazioneMS( unixtime, starttimeM, stoptimeM, starttimeS, stoptimeS);    
      }else if(IrrigMod == 2){
          IrrigazioneFix(unixtime);
      }
      
  return;
  }


int ModalitaIrrigazione(int unixtime,int starttimeM,int stoptimeM,int starttimeS,int stoptimeS){

    if(unixtime <= UNIXDAY/2){     // il mezzogiorno divide mattina e sera
        // Gestione Mattina
        if(unixtime < starttimeM  ||  unixtime > stoptimeM){
            IrrigMod = 2;
          }else if(unixtime >= starttimeM && unixtime <= stoptimeM){
            IrrigMod = 1;
          }
     }else{
        // Gestione Sera
        if(unixtime < starttimeS ||  unixtime > stoptimeS){
            IrrigMod = 2;
          }else if(unixtime >= starttimeS && unixtime <= stoptimeS){
            IrrigMod = 1;
          }
     }
      return IrrigMod;
  }
 
void IrrigazioneMS(int unixtime,int starttimeM,int stoptimeM,int starttimeS,int stoptimeS){
  
     if(unixtime <= UNIXDAY/2){     // il mezzogiorno divide mattina e sera
        // Gestione Mattina
            if(unixtime >= starttimeM && unixtime <= stoptimeM){
              InterruttoreServo(true);
              last_irrig_fix = unixtime;
            }else{
              InterruttoreServo(false);
              }
     }else{
        // Gestione Sera
            if(unixtime >= starttimeS && unixtime <= stoptimeS){
              InterruttoreServo(true);
              last_irrig_fix = unixtime;
            }else{
              InterruttoreServo(false);
              }
     }
    return;
    }

void IrrigazioneFix(int unixtime){
    
    if(irrigazione == true  && unixtime - last_irrig_fix >= (int)EEPROM.read(Address_DURIRGZFIX)){
          Serial.println(F("Irrigazione fissa: "));
          InterruttoreServo(false);
          last_irrig_fix = unixtime;
      }
      if(irrigazione == false  && unixtime - last_irrig_fix >= (int)EEPROM.read(Address_PERIRGZFIX)){
          Serial.println(F("Irrigazione fissa: "));
          InterruttoreServo(true);
          last_irrig_fix = unixtime;
      }
      
  return;
  }

void InterruttoreServo(bool state){
    if(state == true){
      digitalWrite(PUMPPIN, HIGH);
      //ServoPos((int)MAXSERVO);    // Apro
      irrigazione = true;         //aggiorno lo stato
      Serial.println(F("Apro")); 
    }else{
      digitalWrite(PUMPPIN, LOW);
      //ServoPos((int)MINSERVO);    // Chiudo
      irrigazione = false;        //aggiorno lo stato
      Serial.println(F("Chiudo")); 
    }
    
  return;
  }

void StopServo(){
      if(IrrigMod != 0){
        InterruttoreServo(false);
        IrrigMod = 0;
      }else{
         IrrigMod = 1;
      }
  return;
  }
