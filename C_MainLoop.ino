// MAIN LOOP
void loop() {

      int err = OK;
      
      //Clock
      RealTimeClock();
      
      // lettura sensori
      
      err = Lettura_SimpleDHT();
      if(err == ERR_DHT){
          Error_Serial(ERR_DHT);
          return;
        }

      err = Lettura_Luce();
      if(err == ERR_LIGHT){
          Error_Serial(ERR_LIGHT);
          return;
        }  
      
      // comunicazione motore
      Motore();
    
      // comunicazione servo provvisoria
      float posizion = light_percentuale*(MAXSERVO/100);
      ServoPos((int)posizion);

      // Stampo i valori Seriali dopo lettura
      Serial_Out(temperature, humidity , velocity_percentuale, light_percentuale, posizione);
      // Stampo i valori LCD dopo lettura
      LCD_Out(temperature, humidity , velocity_percentuale, light_percentuale);


      if (!(digitalRead(PinSW))) {   // check if button is pressed
    if (RotaryPosition == 0) {  // check if button was already pressed
    } else {
        RotaryPosition=0; // Reset position to ZERO
      }
    }

 
      //Rileva Interrupt
      Detect();
      
      Loop_Serial_div();
      
      // DHT11 sampling rate is 1HZ.
      delay(1000);

      // ripeto


}
