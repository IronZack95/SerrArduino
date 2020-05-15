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
    UI_Status = true;
    Serial.println("Interrupt");
  }

void Detect_Interrupt(){
     // Runs if rotation was detected
      if(TurnDetected){
        PrevPosition = RotaryPosition; // Save previous position in variable
        if (rotationdirection) {
          RotaryPosition=RotaryPosition-1;} // decrase Position by 1
        else {
          RotaryPosition=RotaryPosition+1;} // increase Position by 1
          
        //Gestione Rotary
        if(Mod == false){
          if(RotaryPosition > MAXPAGE-1){
              RotaryPosition = 0;
          }else if(RotaryPosition < 0){
              RotaryPosition = MAXPAGE-1;
          }
        }else{
          if(RotaryPosition > MAXVAR-1){
            RotaryPosition = 0;
          }else if(RotaryPosition < 0){
              RotaryPosition = MAXVAR-1;
          }
        }
    
        //Gestione del finecorsa
        Serial.println("");
        Serial.print("RotaryPosition: "); Serial.println(RotaryPosition);
        Serial.print("MAXPAGE: "); Serial.println(MAXPAGE); Serial.println(Mod);
        Serial.println("");
  
        page = RotaryPosition;
        TurnDetected = false;  // do NOT repeat IF loop until new rotation detected
      }
      return;
  }


void Detect_Button(){
      if (!(digitalRead(PinSW))){   // check if button is pressed
        if(Button == false){          // check se l'evento del bottone è già avvenuto
            /*
            if (RotaryPosition == 0) {  // check if button was already pressed
            } else {
                RotaryPosition=0; // Reset position to ZERO
            }
            */

            //Gestione Buttone
       
              if(UI_Status == true && last_page == MAXPAGE-2){       // entro in modalità  Modifica
                Serial.println("MODALITA MODIFICA");
                Mod = true;
                page = 0;
                RotaryPosition=0;
              }
            

            
            Button = true;
            
            // Salva time dell'ultimo evento
            Last_Unix_time = dt.unixtime;                  // scateno simil interrupt
            UI_Status = true;
            Serial.println("Button Interrupt");
        }
      }else{
          Button = false;
      }
      return;
  }
