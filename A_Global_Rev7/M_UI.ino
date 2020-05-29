void UI(){  
    
    //Serial.println("MENU\t");
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

      err = Lettura_Temperatura();
      if(err == ERR_TEMP){
          Error_Serial(ERR_TEMP);
          return err;
        }  

      //ReciverLoop();  

      // comunicazione Motore
      
      Motore();

      // comunicazione Relè

      GestioneRelay();
      

      // comunicazione Servo
      //ServoLight();

      // Stampa
      if(mod == 0){
          // Stampo i valori Seriali dopo lettura
          Serial_Out_Auto(temperature, Analog_Temp , humidity , velocity_percentuale, light_percentuale, posizione);
          // Stampo i valori LCD dopo lettura
          LCD_Out_Auto(temperature, humidity , velocity_percentuale, light_percentuale);
      }

    return OK;
  }
