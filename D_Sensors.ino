
//------------------------------------- FUNZIONI -----------------------------------

int Lettura_SimpleDHT(){

      // read without samples - read Sensors
      if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
        return ERR_DHT;
      }

      return OK;
  }

int Lettura_Luce(){
      // Read photocell
      light  = analogRead(LIGHTPIN);
      light_percentuale = (int)abs(light-MAXLIGHT)*(100./MAXLIGHT);
      if(light < 0 && light > MAXLIGHT){
            return ERR_LIGHT;
        }
      
      return OK;    
  }
