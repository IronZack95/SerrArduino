// MAIN LOOP

void loop() {

      int err = OK;
      
      //Inizio con i rilevamenti
      //Clock
      RealTimeClock();

      //Rileva Interrupt
      Detect_Interrupt();

      //Rileva Bottone
      Detect_Button();
      
      //Rileva Allarme
      Detect_Allarm();

      if(mod != 0){                     //-----------  ENTRA IN MODALITA' UI
            UI(); 
            // Verifico che sia passato un tot di tempo dall'ultimo interrupt
            UItoAUTOMATIC();
            del = UI_SAMPLING_RATE;             // Sampling Rate
            skip = skip + UI_SAMPLING_RATE;
            if(skip >= AUTOMATIC_SAMPLING_RATE){
              //Esegue automatismo
              err = Automatic();
              if(err != OK)
                return;
              skip = 0;              
            }
                       
      }else{                                      //-----------  ENTRA IN MODALITA' AUTOMATICA
            //Esegue automatismo
            err = Automatic();
            Loop_Serial_div();      // Divisorio  
            del = AUTOMATIC_SAMPLING_RATE;      // Sampling Rate
      }

      // Leggo quello che ho scitto dalla porta Seriale
      Serial_Read();
      
      // ripeto
      //Loop_Serial_div();      // Divisorio
      delay(del);

}
