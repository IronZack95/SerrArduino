void GestioneRiscaldamento(){

  if((int)temperature < EEPROM.read(Address_MINTEMP) && Relay_State == false){
    Relay(true);    
  } else if((int)temperature >= EEPROM.read(Address_MINTEMP) && Relay_State == true){
    Relay(false);  
  }
  return;
  }

void Relay(bool state){
    if(state == true){
      digitalWrite(RELAY,HIGH);
      Serial.println(F("Accendo Relè")); 
    }else{
      digitalWrite(RELAY,LOW);
      Serial.println(F("Spengo Relè")); 
    }
    Relay_State = state;
  return;
  }

void InterruttoreRelay(){
    if(Relay_State == true){
      Relay(false);
    }else if(Relay_State == false){
      Relay(true); 
      }      
  return;
  }
