void GestioneIrrigazione(){
  
    Serial.println(F("GESTIONE IRRIGAZIONE"));
    unsigned long unixday = (int)dt.second+((int)dt.minute)*60UL+((int)dt.hour)*3600UL;
    Serial.print("dt.second "); Serial.print((int)dt.second);Serial.print(" dt.minute "); Serial.print((int)dt.minute); Serial.print(" dt.hour "); Serial.println((int)dt.hour);
    Serial.print("unixday: ");Serial.println(unixday);
    
    unsigned long starttimeM =  EEPROM.read(Address_MATNSTRT_H)*3600UL + EEPROM.read(Address_MATNSTRT_M)*60UL;
    unsigned long stoptimeM = starttimeM + EEPROM.read(Address_DURIRRIG_S) + EEPROM.read(Address_DURIRRIG_M)*60UL;
    Serial.print("START TIME MATT ");Serial.print(starttimeM); Serial.print(" STOP TIME MATT "); Serial.println(stoptimeM);
    
    unsigned long starttimeS =  (EEPROM.read(Address_SERASTRT_H)*3600UL) +(EEPROM.read(Address_SERASTRT_M)*60UL);
    unsigned long stoptimeS = starttimeS + EEPROM.read(Address_DURIRRIG_S) + EEPROM.read(Address_DURIRRIG_M)*60UL;
    Serial.print("START TIME SERA ");Serial.print(starttimeS);  Serial.print(" STOP TIME SERA "); Serial.println(stoptimeS);

      Serial.print("Modalità irrigazione: ");
      if(IrrigMod != 0){ // verifico che l'irrigazione non sia disattivata
          IrrigMod = ModalitaIrrigazione(unixday, starttimeM, stoptimeM, starttimeS, stoptimeS); // ottengo la precedenza tra le due modalità
          Serial.print("Attiva - ");  Serial.println(IrrigMod);
      }else{
          Serial.print("Disattiva - ");  Serial.println(IrrigMod);
      }
      if(IrrigMod == 1){        // "mattina e sera"
          IrrigazioneMS( unixday, starttimeM, stoptimeM, starttimeS, stoptimeS);    
      }else if(IrrigMod == 2){  // " fissa ogni tot"
          IrrigazioneFix(unixday);
      }
      
  return;
  }


int ModalitaIrrigazione(unsigned long unixday,unsigned long starttimeM,unsigned long stoptimeM,unsigned long starttimeS,unsigned long stoptimeS){
    // con questa funzione do precedenza all'irrigazione mattina sera piuttosto che a quella fissa
    if(unixday <= UNIXDAY/2){     // il mezzogiorno divide mattina e sera
        // Gestione Mattina
        if(unixday < starttimeM  ||  unixday > stoptimeM){
            IrrigMod = 2;
          }else if(unixday >= starttimeM && unixday <= stoptimeM){
            IrrigMod = 1;
          }
     }else{
        // Gestione Sera
        if(unixday < starttimeS ||  unixday > stoptimeS){
            IrrigMod = 2;
          }else if(unixday >= starttimeS && unixday <= stoptimeS){
            IrrigMod = 1;
          }
     }
      return IrrigMod;
  }
 
void IrrigazioneMS(unsigned long unixday,unsigned long starttimeM,unsigned long stoptimeM,unsigned long starttimeS,unsigned long stoptimeS){
  
     if(unixday <= UNIXDAY/2){     // il mezzogiorno divide mattina e sera
        // Gestione Mattina
            if(unixday >= starttimeM && unixday <= stoptimeM){
              Pompa(true);
              last_irrig_fix = dt.unixtime;
            }else{
              Pompa(false);
              }
     }else{
        // Gestione Sera
            if(unixday >= starttimeS && unixday <= stoptimeS){
              Pompa(true);
              last_irrig_fix = dt.unixtime;
            }else{
              Pompa(false);
              }
     }
    return;
    }

void IrrigazioneFix(unsigned long unixday){
    
    if(irrigazione == true  && dt.unixtime - last_irrig_fix >= (int)EEPROM.read(Address_DURIRGZFIX)){
          Serial.println(F("Irrigazione fissa: "));
          Pompa(false);
          last_irrig_fix = dt.unixtime;
      }
      if(irrigazione == false  && dt.unixtime - last_irrig_fix >= ((int)EEPROM.read(Address_PERIRGZFIX)*60UL  && (int)EEPROM.read(Address_DURIRGZFIX) != 0)){ // non accendo se la durata dell'irrigazione è 0 secondi
          Serial.println(F("Irrigazione fissa: "));
          Pompa(true);
          last_irrig_fix = dt.unixtime;
      }
      
  return;
  }

void Pompa(bool state){
  noInterrupts();
    if(state == true){
      digitalWrite(PUMPPIN, HIGH);
      irrigazione = true;         //aggiorno lo stato
      Serial.println(F("Apro Irrigazione")); 
    }else{
      digitalWrite(PUMPPIN, LOW);
      irrigazione = false;        //aggiorno lo stato
      Serial.println(F("Chiudo Irrigazione")); 
    }
  delay(500);
  interrupts();
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
