int Lettura_SimpleDHT(){
      // read without samples - read Sensors
      if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
        return ERR_DHT;
      }
      return OK;
  }

float Lettura_Temperatura(){      // lettura sensore temperatura analogico
      int Lettura  = analogRead(ANLGTMP);
      if(Lettura < 0 && Lettura > MAXADC){
            return ERR_TEMP;
        }
      double tempK = log(10000.0 * ((1024.0 / Lettura - 1)));
      tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
      float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
      //float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
      Analog_Temp = tempC;
      return OK;
  }

int Lettura_Luce(){
      // Read photocell
      light  = analogRead(LIGHTPIN);
      light_percentuale = (int)abs(light)*(100./MAXADC);
      if(light < 0 && light > MAXADC){
            return ERR_LIGHT;
        }
      return OK;    
  }
