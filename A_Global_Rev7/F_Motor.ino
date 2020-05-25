
void InterrutoreVentilazione(){
    if(ventilazione == true){
            Serial.println("Ventilazione OFF");
            ventilazione = false;
    }else{
            Serial.println("Ventilazione ON");
            ventilazione = true;
      }
  return;
  }

void Motore(){

      //ACCENSIONE  ---------------------------------------------------------------------------------------------
        if((int)temperature > EEPROM.read(Address_TH) && (int)temperature <= EEPROM.read(Address_MAXTEMP) && ventilazione == true){
            //---PWM

        //calcolo velocità
        float new_velocity = ((MAXVEL - MINVEL)/(EEPROM.read(Address_MAXTEMP) - EEPROM.read(Address_TH)))*pow(((int)temperature - EEPROM.read(Address_TH)),rapporto)   + MINVEL;

        if(velocity == 0){                            // Aiuta a partire nel caso parta da fermo
              digitalWrite(ENABLE,LOW); //enable off
              for(int ii = 0; ii <= StepAvvio ; ii++){
                analogWrite(ENABLE,(int)((int)new_velocity/StepAvvio)*ii); //enable on
                delay(TimeAvvio/StepAvvio);
              }
          }
        // A REGIME

        velocity = new_velocity;
        //Serial.println(int(velocity));
        analogWrite(ENABLE,(int)velocity);  // Velocità a regime

        }

      // SPEGNIMENTO  ---------------------------------------------------------------------------------------------
        if((int)temperature <= EEPROM.read(Address_TH) || (int)temperature> EEPROM.read(Address_MAXTEMP) || ventilazione == false){
            Serial.println("spengo motore");
            //---PWM
            velocity = 0;
            digitalWrite(ENABLE,LOW); //enable off
            if((int)temperature> EEPROM.read(Address_MAXTEMP)){
              Serial.println("MAXTEMP SUPERATA - - - - - ERRORE");
              return;
            }
        }

        // gestion cionversoni
        velocity_percentuale = (int)velocity*(100./MAXVEL);

    return;
  }
