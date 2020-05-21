// Interrupt routine runs if CLK goes from HIGH to LOW
void isr ()  {
    delay(4);  // delay for Debouncing
    if (digitalRead(PinCLK))
      rotationdirection= digitalRead(PinDT);
    else
      rotationdirection= !digitalRead(PinDT);
      

    // Salva time dell'ultimo evento
    Last_Unix_time = dt.unixtime;
    TurnDetected = true;
    Serial.println("Rotary Interrupt");
  }

void Detect_Interrupt(){
     // Runs if rotation was detected
      if(TurnDetected){
        PrevPosition = RotaryPosition; // Save previous position in variable
        if (rotationdirection) {
          RotaryPosition=RotaryPosition-1;} // decrase Position by 1
        else {
          RotaryPosition=RotaryPosition+1;} // increase Position by 1
        
        // Gestione Rotary  
        Gestione_Rotary();

        
        Serial.println("");
        Serial.print("RotaryPosition: "); Serial.println(RotaryPosition);
        Serial.print("MAXPAGE: "); Serial.println(MAXPAGE-1); Serial.print("modalità: "); Serial.println(mod);
        Serial.println("");
        
        TurnDetected = false;  // do NOT repeat IF loop until new rotation detected
      }
      return;
  }

void Gestione_Rotary(){
    
    //Gestione Rotary
    if(mod == 0 || mod == 1){               // modalità MENU
      if(RotaryPosition > MAXPAGE-1){
          RotaryPosition = 0;
      }else if(RotaryPosition < 0){
          RotaryPosition = MAXPAGE-1;
      }
      // Gestione pagina
      page = RotaryPosition;
      mod = 1;
    }
    
    if(mod == 2){                
      // modalità MODIFICA
      if(RotaryPosition > MAXVAR){
        RotaryPosition = 0;
      }else if(RotaryPosition < 0){
          RotaryPosition = MAXVAR;
      }
      
      //Gestione pagina
      switch(RotaryPosition){
                case 0: case 1:                 page = 0; break;
                case 2:                         page = 1; break;
                case 3: case 4:                 page = 2; break;
                case 5:                         page = 3; break;
                case 6:                         page = 4; break;
                case 7: case 8: case 9: case 10: page = 5; break;
                case 11: case 12:               page = 6; break;
                case 13:                        page = 7; break;
                case 14:                        page = 8; break;
                default:
                  break;
        }
    }

    if(mod == 3){
           int_table[Sel] = RotaryPosition;
        }
    
    return;
    }

void Detect_Button(){
      if (!(digitalRead(PinSW))){   // check if button is pressed
        if(Button == false){          // check se l'evento del bottone è già avvenuto
           Button = true;
           Serial.println("Button Interrupt");
           //Gestione Bottone
           Gestione_Bottone();
           // Salva time dell'ultimo evento
           Last_Unix_time = dt.unixtime;                  // scateno simil interrupt
        }
      }else{
            Button = false;
      }
      return;
  }

void Gestione_Bottone(){
    //if(Button == true){
    
          if(mod == 0){       // entro in modalità  MENU
            Serial.println("MODALITA MENU'");
            mod = 1;
            Sel = -1;
            page = 0;
            RotaryPosition=0;          
          }

          //Gestione Buttone
          if(mod == 3){       // Confermo cambiamento
            Serial.println("MODIFICA EFFETTUATA");
            RAM_to_EEPROM_Update();
            mod = 0;
            Sel = -1;      
          }
          
          if(mod == 2){       // entro in modalità  selezione
            Serial.println("MODALITA SELEZIONE");
            mod = 3;
            Sel = RotaryPosition;
            RotaryPosition = int_table[Sel];
          }

          if(mod == 1 && page == MAXPAGE-2){       // entro in modalità  Modifica
            Serial.println("MODALITA MODIFICA");
            mod = 2;
            page = 0;
            Sel = -1;
            RotaryPosition=0;
          }
           
      //}
    return;
  }
