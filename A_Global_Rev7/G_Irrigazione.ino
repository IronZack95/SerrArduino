void GestioneIrrigazione(){
  
    Serial.println(F("GESTIONE IRRIGAZIONE"));
    int unixtime = (int)dt.second + 60*(int)dt.minute + 60*60*(int)dt.hour;
    Serial.print("UNIXTIME ");Serial.println(unixtime);
    //Serial.println(unixtime);
    int starttimeM =  60*(int)EEPROM.read(Address_MATNSTRT_M) + 60*60*(int)EEPROM.read(Address_MATNSTRT_H);
    int stoptimeM = starttimeM + (int)EEPROM.read(Address_DURIRRIG_S) + 60*(int)EEPROM.read(Address_DURIRRIG_M);
    Serial.print("START TIME MATT ");Serial.print(starttimeM); Serial.print(" STOP TIME MATT "); Serial.println(stoptimeM);
    
    int starttimeS =  60*(int)EEPROM.read(Address_SERASTRT_M) + 60*60*(int)EEPROM.read(Address_SERASTRT_H);
    int stoptimeS = starttimeS + (int)EEPROM.read(Address_DURIRRIG_S) + 60*(int)EEPROM.read(Address_DURIRRIG_M);
    Serial.print("START TIME SERA ");Serial.print(starttimeS);  Serial.print(" STOP TIME SERA "); Serial.println(stoptimeS);
  
      if(IrrigMod != 0){ // verifico che l'irrigazione non sia disattivata
          IrrigMod = ModalitaIrrigazione(unixtime, starttimeM, stoptimeM, starttimeS, stoptimeS); // ottengo la precedenza tra le due modalità
          Serial.print("Modalità: ");  Serial.println(IrrigMod);
      }
      if(IrrigMod == 1){        // "mattina e sera"
          IrrigazioneMS( unixtime, starttimeM, stoptimeM, starttimeS, stoptimeS);    
      }else if(IrrigMod == 2){  // " fissa ogni tot"
          IrrigazioneFix(unixtime);
      }
      
  return;
  }


int ModalitaIrrigazione(int unixtime,int starttimeM,int stoptimeM,int starttimeS,int stoptimeS){
    // con questa funzione do precedenza all'irrigazione mattina sera piuttosto che a quella fissa
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
              Pompa(true);
              last_irrig_fix = unixtime;
            }else{
              Pompa(false);
              }
     }else{
        // Gestione Sera
            if(unixtime >= starttimeS && unixtime <= stoptimeS){
              Pompa(true);
              last_irrig_fix = unixtime;
            }else{
              Pompa(false);
              }
     }
    return;
    }

void IrrigazioneFix(int unixtime){
    
    if(irrigazione == true  && unixtime - last_irrig_fix >= (int)EEPROM.read(Address_DURIRGZFIX)){
          Serial.println(F("Irrigazione fissa: "));
          Pompa(false);
          last_irrig_fix = unixtime;
      }
      if(irrigazione == false  && unixtime - last_irrig_fix >= 60*(int)EEPROM.read(Address_PERIRGZFIX)){
          Serial.println(F("Irrigazione fissa: "));
          Pompa(true);
          last_irrig_fix = unixtime;
      }
      
  return;
  }

void Pompa(bool state){
    if(state == true){
      digitalWrite(PUMPPIN, HIGH);
      irrigazione = true;         //aggiorno lo stato
      Serial.println(F("Apro Irrigazione")); 
    }else{
      digitalWrite(PUMPPIN, LOW);
      irrigazione = false;        //aggiorno lo stato
      Serial.println(F("Chiudo Irrigazione")); 
    }
    
  return;
  }

void InterruttorePompa(){
  if(irrigazione == true){
    Pompa(false);
    irrigazione = false;
  }else if(irrigazione == false){
    Pompa(true); 
    irrigazione = true;
    }      
return;
}

void StopPompa(){
      if(IrrigMod != 0){
        Pompa(false);
        IrrigMod = 0;
      }else{
         IrrigMod = 1;
      }
  return;
  }
