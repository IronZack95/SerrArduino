void LCD_Out_UI(){

        char buffer[16];  // make sure this is large enough for the largest string it must hold
        int posizione_cursore = -1;
        if(temperature != last_temperature || light_percentuale != last_light_percentuale || RotaryPosition != last_RotaryPosition){         // Solo alla variazione di qualche variabile per evitare lo sfarfallio
            
            last_temperature = temperature;
            last_light_percentuale = light_percentuale;
            last_RotaryPosition = RotaryPosition;
           
            //Stampo template di base della pagina
            lcd.clear();               // Refresh
            lcd.setCursor(0, 0);       // Riparto col cursore 0,0
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[page*2]))); lcd.print(buffer);
            lcd.setCursor(0, 1);   
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[page*2 + 1]))); lcd.print(buffer);     

            
            
            if(mod == 0 || mod == 1){
              lcd.noCursor();
              }
              
            //Stampo overlay
            switch(page){
                  case 0:
                     lcd.setCursor(5, 0);    lcd.print((int)temperature); lcd.setCursor(8, 0);    lcd.write(byte(0));  
                     //lcd.setCursor(4, 1);    lcd.print((int)EEPROM.read(Address_TH));   lcd.setCursor(13, 1);    lcd.print((int)EEPROM.read(Address_MAXTEMP));
                     lcd.setCursor(4, 1);    lcd.print((int)int_table[0]);   lcd.setCursor(13, 1);    lcd.print((int)int_table[1]);
                  break;
                  case 1:                                     
                     //lcd.setCursor(5, 1);    lcd.print((int)EEPROM.read(Address_MINTEMP));  lcd.setCursor(8, 1);    lcd.write(byte(0)); 
                     lcd.setCursor(5, 1);    lcd.print((int)int_table[2]);  lcd.setCursor(8, 1);    lcd.write(byte(0));
                  break;
                  case 2:
                     lcd.setCursor(11, 0);    lcd.print((int)humidity);
                     //lcd.setCursor(5, 1);    lcd.print((int)EEPROM.read(Address_MINUMID));   lcd.setCursor(13, 1);    lcd.print((int)EEPROM.read(Address_MAXUMID));
                     lcd.setCursor(5, 1);    lcd.print((int)int_table[3]);   lcd.setCursor(13, 1);    lcd.print((int)int_table[4]);
                  break;
                  case 3:
                     //lcd.setCursor(6, 1);    lcd.print((int)EEPROM.read(Address_PERVENT));
                     lcd.setCursor(6, 1);    lcd.print((int)int_table[5]);
                  break;
                  case 4:
                     //lcd.setCursor(6, 1);    lcd.print((int)EEPROM.read(Address_DURVENT));
                     lcd.setCursor(6, 1);    lcd.print((int)int_table[6]);
                  break;
                  case 5:
                     //lcd.setCursor(2, 1);    lcd.print((int)EEPROM.read(Address_MATNSTRT_H)); lcd.setCursor(5, 1);    lcd.print((int)EEPROM.read(Address_MATNSTRT_M));
                     //lcd.setCursor(10, 1);    lcd.print((int)EEPROM.read(Address_SERASTRT_H)); lcd.setCursor(13, 1);    lcd.print((int)EEPROM.read(Address_SERASTRT_M)); 
                     lcd.setCursor(2, 1);    lcd.print((int)int_table[7]); lcd.setCursor(5, 1);    lcd.print((int)int_table[8]);
                     lcd.setCursor(10, 1);    lcd.print((int)int_table[9]); lcd.setCursor(13, 1);    lcd.print((int)int_table[10]); 
                  break;
                  case 6:
                      //lcd.setCursor(1, 1);    lcd.print((int)EEPROM.read(Address_DURIRRIG_H));  lcd.setCursor(9, 1);    lcd.print((int)EEPROM.read(Address_DURIRRIG_M));
                      lcd.setCursor(1, 1);    lcd.print((int)int_table[11]);  lcd.setCursor(9, 1);    lcd.print((int)int_table[12]);
                  break;
                  case 7:
                      //lcd.setCursor(6, 1);    lcd.print((int)EEPROM.read(Address_PERIRGZFIX));
                      lcd.setCursor(6, 1);    lcd.print((int)int_table[13]);
                  break;
                  case 8:
                      //lcd.setCursor(6, 1);    lcd.print((int)EEPROM.read(Address_DURIRGZFIX));
                      lcd.setCursor(6, 1);    lcd.print((int)int_table[14]);
                  break;
                  case 9:
                      lcd.setCursor(7, 1);    lcd.print((int)light_percentuale);
                  break;
                  default:
                  break;
            }
            
            //Overlay modifica
              if(mod == 2 || mod == 3){
                  if(mod == 2){                           // se sono in modalità 2 ovvero nel pannello modifica mi interessa spostare il cursore
                   posizione_cursore = RotaryPosition;
                  }else if (mod == 3){ 
                    posizione_cursore = Sel;              // se invece sono in modalità 3 e sto cambiando il valore della variabile, mi interessa avere il cursore fisso
                  }
                
                  switch(posizione_cursore){
                      case 0:  lcd.setCursor(4, 1);  break;
                      case 1:  lcd.setCursor(13, 1);  break;
                      case 2:  lcd.setCursor(5, 1);  break;
                      case 3:  lcd.setCursor(5, 1);  break;
                      case 4:  lcd.setCursor(13, 1);  break;
                      case 5:  lcd.setCursor(6, 1);  break;
                      case 6:  lcd.setCursor(6, 1);  break;
                      case 7:  lcd.setCursor(2, 1);  break;
                      case 8:  lcd.setCursor(5, 1);  break;
                      case 9:  lcd.setCursor(10, 1);  break;
                      case 10:  lcd.setCursor(13, 1);  break;
                      case 11:  lcd.setCursor(1, 1);  break;
                      case 12:  lcd.setCursor(9, 1);  break;
                      case 13:  lcd.setCursor(6, 1);  break;
                      case 14:  lcd.setCursor(6, 1);  break;
                      default:
                        break;
                  }  
                  //Stampo carattere modifica  
                  lcd.cursor();
              }
        }

        return;
  };

void Serial_Out_Auto(byte t, byte u, int v, int l , int p){

        // Print to Serial

        //System Time
        Serial.print("Raw data: ");
        Serial.print(dt.year);   Serial.print("-");
        Serial.print(dt.month);  Serial.print("-");
        Serial.print(dt.day);    Serial.print(" ");
        Serial.print(dt.hour);   Serial.print(":");
        Serial.print(dt.minute); Serial.print(":");
        Serial.print(dt.second); Serial.println("");

        Serial.print("Unix Time: "); Serial.print(dt.unixtime); Serial.println("");
        
        //Serial.println("Sample OK: ");
        
        Serial.print("Temperatura: "); Serial.print((int)t); Serial.println(" *C, ");
        Serial.print("Velocità Motore: "); Serial.print((int)v); Serial.println(" %, "); 
        
        Serial.print("Luce: "); Serial.print((int)l); Serial.println(" %, ");
        Serial.print("Servo: "); Serial.print((int)p); Serial.println(" gradi, ");

        Serial.print("Umidità: "); Serial.print((int)u); Serial.println(" %");

      return;
  }

void LCD_Out_Auto(byte t, byte u, int v, int l){
  
        // Print a message to the LCD.       
        lcd.clear();
        lcd.noCursor();
        lcd.setCursor(0, 0);
        lcd.print("Temp:");   lcd.print((int)t);
        lcd.setCursor(8, 0);
        lcd.print("Umid:");   lcd.print((int)u); //lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Luce:");   lcd.print((int)l); //lcd.print("%");
        lcd.setCursor(8, 1);
        lcd.print("Velo:"); lcd.print((int)v); //lcd.print("%");
        
        return;
}

void Error_Serial(int err){
        
        switch(err){
          
            case ERR_DHT:
                  Serial.println("ERRORE  - LETTURA SENSORE TEMPERATURA");
              break;
              
            case ERR_LIGHT:
                Serial.println("ERRORE  - LETTURA FOTORESISTENZA");
            break;
            
            default:
                  Serial.println("ERRORE NON IDENTIFICATO");
              break;
        }
  
        Error_Serial_div();
        return;
  }

void Setup_LCD(){
         lcd.clear();
         lcd.setCursor(0, 0);    
         lcd.print(" -- STARTING -- ");
         return;
  }

void Setup_Serial(){
        Serial.println("");
        Serial.println("ooooooooooooo SETUP ooooooooooooo");
        return;
  }

void Loop_Serial_div(){
        // start working...
        Serial.println("=================================");
        return;
  }

void Setup_Serial_div(){
        // start working...
        Serial.println("*********************************");
        return;
  }
  
void Error_Serial_div(){
        // start working...
        Serial.println("ooooooooooooooooooooooooooooooooo");
        return;
  }
