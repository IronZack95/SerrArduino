void Serial_Read(){

//Comunicazione Seriale
char IncomingChar; 

/*
String scan =   "scan";
String reset =  "reset";
String EtoR =   "EtoR";
String RtoE =   "RtoE";
String clean =  "clean";
*/

      // send data only when you receive data:
      if (Serial.available() > 0) {
            // read the incoming byte:
            IncomingChar = Serial.read();

            // say what you got:
            Serial.print(F("I received: "));
            Serial.println(IncomingChar);
      
      if(IncomingChar == scan){
          EEPROM_Scan();
      }else if(IncomingChar == reset){
          EEPROM_RAM_ResetToDefault();
      }else if(IncomingChar == EtoR){
          EEPROM_to_RAM_Update();
      }else if(IncomingChar == RtoE){
          RAM_to_EEPROM_Update();
      }else if(IncomingChar == clean){
          EEPROM_Clean();
      }else if(IncomingChar == resetRTC){
          clock.setDateTime(__DATE__, __TIME__);
      }else if(IncomingChar == StopVent){
          InterrutoreVentilazione();
      }else if(IncomingChar == StopServ){
           StopServo();
      }else if(IncomingChar == ModVar){
           ModificaVariabili();
      }else if(IncomingChar == relay){
           InterruttoreRelay();
      }
   }
    return;
}

void ModificaVariabili(){
  bool x = false;
  char IncomingChar; 
 
  // Scan
  Serial.println();   
  Serial.print(F("Modifica una variabile tra le ")); Serial.print(sizeof(int_table));  Serial.println(F(" disponibili"));
  Serial.println(); 
  EEPROM_Scan();
  

  while(!x){
      if(Serial.available() > 0){
      // read the incoming byte:
      IncomingChar = Serial.read();
      
      x = true;
      // say what you got:
      Serial.print(F("I received: "));
      Serial.println(IncomingChar);
     }
   }
   return;
  }
