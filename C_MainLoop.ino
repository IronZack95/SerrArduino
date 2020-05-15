// MAIN LOOP
void loop() {

  // MAIN
  while(1){
      // start working...
      Serial.println("=================================");
      Serial.println("Sample DHT11...");

      // read without samples - read Sensors
        
      if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
        Serial.print("Read DHT11 failed.");
        return 0;
      }

      // lettura sensori
      Lettura_Sensori();
      
      // comunicazione motore
      Motore();

      // comunicazione servo provvisoria
      float posizion = light_percentuale*(MAXSERVO/100);
      ServoPos((int)posizion);

      // Stampo i valori Seriali dopo lettura
      Serial_Out(temperature, humidity , velocity_percentuale, light_percentuale, posizione);
      // Stampo i valori LCD dopo lettura
      LCD_Out(temperature, humidity , velocity_percentuale, light_percentuale);
     
      //Clock
      RealTimeClock();
      
      // DHT11 sampling rate is 1HZ.
      delay(1000);

      // ripeto

 }

}
