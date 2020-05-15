void UI(){  
    
    Serial.println("MENU\t");
    /*
    Serial.print("unix time: "); Serial.print(dt.unixtime); Serial.print("\t");
    Serial.print("last unix time: "); Serial.print(Last_Unix_time); Serial.print("\t");
    Serial.print("differenza: ");Serial.println(abs(dt.unixtime - Last_Unix_time));
    */
    /*
    //Gestione Rotary
    if(RotaryPosition > MAXPAGE-1){
        RotaryPosition = 0;
    }else if(RotaryPosition < 0){
        RotaryPosition = MAXPAGE-1;
    }
     
    //Gestione Buttone
    if(Button == true){
      if(UI_Status == true && last_page == MAXPAGE-2){       // entro in modalità  Modifica
        Serial.println("MODALITA MODIFICA");
        Mod = true;
        page = 0;
        RotaryPosition=0;
      }
    } 
    */
    
         
    LCD_Out_UI();

    return;
  }

void Modifica(){
  
    Serial.println("MODIFICA\t");
  
    //Gestione Rotary
    if(RotaryPosition > MAXVAR-1){
        RotaryPosition = 0;
    }else if(RotaryPosition < 0){
        RotaryPosition = MAXVAR-1;
    }
             
    
    LCD_Out_UI();

  return;
  }




int Automatic(){
      // lettura sensori
      int err = OK;
      
      err = Lettura_SimpleDHT();
      if(err == ERR_DHT){
          Error_Serial(ERR_DHT);
          return err;
        }

      err = Lettura_Luce();
      if(err == ERR_LIGHT){
          Error_Serial(ERR_LIGHT);
          return err;
        }  
      
      // comunicazione motore
      Motore();
    
      // comunicazione servo provvisoria
      float posizion = light_percentuale*(MAXSERVO/100);
      if((int)posizion != posizione) {
          ServoPos((int)posizion);
      }

      // Stampa
      if(UI_Status == false){
          // Stampo i valori Seriali dopo lettura
          Serial_Out_Auto(temperature, humidity , velocity_percentuale, light_percentuale, posizione);
          // Stampo i valori LCD dopo lettura
          LCD_Out_Auto(temperature, humidity , velocity_percentuale, light_percentuale);
      }

    return OK;
  }
