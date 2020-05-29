/*
EEPROM.write(address, value)  Write a byte to the EEPROM.
EEPROM.read(address)          Reads a byte from the EEPROM. Locations that have never been written to have the value of 255.
EEPROM.get(address, data)     Read any data type or object from the EEPROM.
EEPROM.put(address, data)     Write any data type or object to the EEPROM.
EEPROM.update(address, value) Write a byte to the EEPROM. The value is written only if differs from the one already saved at the same address.
EEPROM[address]               This operator allows using the identifier `EEPROM` like an array. EEPROM cells can be read and written directly using this method.
*/

void EEPROM_Clean(){
      //Cancella la eeprom dall'inizio fino all'address lunghezza
      for (int i = 0 ; i < MAXVAR ; i++) {
          EEPROM.update(int_table_Address[i], 0);
      }
      
      Serial.println(F("EEPROM CLEAN - DONE")); 
      return;

  }

void EEPROM_Scan(){
      Serial.println(F("EEPROM Scan"));
      Serial.println(F("Address       RAM   EEPROM"));

      for (int i = 0 ; i < MAXVAR ; i++) {
          byte value = EEPROM.read(int_table_Address[i]);
          
          Serial.print(int_table_Address[i]);
          Serial.print(F("\t")); Serial.print(F("\t"));
          Serial.print(int_table[i]);
          Serial.print(F("\t"));
          Serial.print(value);
          Serial.println();
         
          if (i == EEPROM.length()){
            i = 0;}
      }
      return;
  }

void EEPROM_RAM_ResetToDefault(){
      byte int_table_1[] = {TH,MAXTEMP,MINTEMP,MINUMID,MAXUMID,PERVENT,DURVENT,MATNSTRT_H,MATNSTRT_M,SERASTRT_H,SERASTRT_M,DURIRRIG_H,DURIRRIG_M,PERIRGZFIX,DURIRGZFIX};
      //ripulisco fino a dove mi serve
      //EEPROM_Clean();
      // update fino a dove mi serve
      for (int i = 0; i < MAXVAR; i++){
        EEPROM.update(int_table_Address[i], int_table_1[i]);
        int_table[i] = int_table_1[i];
      }
      
      return;
      Serial.println(F("Reset To Default")); 
  }
  
void  EEPROM_to_RAM_Update(){
       Serial.println(F("RAM Update"));
       for (int i = 0 ; i < MAXVAR ; i++) {
          if(int_table[i] != EEPROM.read(int_table_Address[i])){
              int_table[i] = EEPROM.read(int_table_Address[i]); 
          }
       }      
      return;
  }

void  RAM_to_EEPROM_Update(){
       Serial.println(F("EEPROM Update"));
       for (int i = 0; i < MAXVAR; i++)
        EEPROM.update(int_table_Address[i], int_table[i]);
   
      return;
  }
