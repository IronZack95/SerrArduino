void RealTimeClock(){
      //Aggiorna l'orologio
      dt = clock.getDateTime();
      if(IrrigMod != 0 && irrigazione == true){ // se l'irrigazione è accesa allora entro nel ciclo di gestione senza aspettare il timer, così posso calcolare i secondi finemente
        GestioneIrrigazione();
      }
      return;
  }

void UItoAUTOMATIC(){
    // verifico se nulla viene premuto per il tempo ATTESAMENU
    if( abs(dt.unixtime - Last_Unix_time) >= ATTESAMENU){
        mod = 0;
        RotaryPosition=0;
      }
    return;
}

void Detect_Allarm(){
      // Call isAlarm1(false) if you want clear alarm1 flag manualy by clearAlarm1();
      if (clock.isAlarm1()){
        //Serial.println(F("ALARM 1 TRIGGERED!"));
        }
    
      // Call isAlarm2(false) if you want clear alarm1 flag manualy by clearAlarm2();
      if (clock.isAlarm2()){
        Serial.println(F("ALARM 2 TRIGGERED!"));
        //Gestisco l'irrigazione ogni minuto
        GestioneIrrigazione();
        }
      
    return;
  }
