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

      if(UI_Status == true){                     //-----------  ENTRA IN MODALITA' UI
            //if(Mod == true){  
               // Modifica();
            //}else{
                UI();
              //}

            // Verifico che sia passato un tot di tempo dall'ultimo interrupt
            
            UItoAUTOMATIC();
            del = UI_SAMPLING_RATE;   
            
            skip = skip + UI_SAMPLING_RATE;
            if(skip >= AUTOMATIC_SAMPLING_RATE){
              //Esegue automatismo
              err = Automatic();
              if(err != OK){
                return;
                }
              skip = 0;              
            }
                       
      }else{                                      //-----------  ENTRA IN MODALITA' AUTOMATICA
            
            //Esegue automatismo
            err = Automatic();
            if(err != OK){
              return;
              }
              
            //sampling rate is 1HZ.
            del = AUTOMATIC_SAMPLING_RATE; 
      }


      // ripeto
      Loop_Serial_div();
      delay(del);

}
