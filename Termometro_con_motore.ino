//www.elegoo.com
//2016.12.12

#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2


/************************
Exercise the motor using
the L293D chip
************************/
// define motore
#define ENABLE 5
#define DIRA 3
#define DIRB 4

// define mie
#define threshold 24     // gradi a cui si attiva la ventola
#define MAXTEMP 30        // grado limite a cui da errore
#define MAXVEL 255        //    massima velocità
#define MINVEL 150         //  minima velocità
#define n 1               // rapporto della curva

// variabili temperatura
int i;
int pinDHT11 = 2;
SimpleDHT11 dht11;

// Variabili mie
int SH = 0; 
int velocity = 0;




void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}



void loop() {
  // main
  while(1){
    
      // start working...
      Serial.println("=================================");
      Serial.println("Sample DHT11...");
    
       // read without samples.
      byte temperature = 0;
      byte humidity = 0;
      if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
        Serial.print("Read DHT11 failed.");
        return;
      }
        
      Serial.print("Sample OK: ");
      Serial.print((int)temperature); Serial.print(" *C, "); 
      Serial.print((int)humidity); Serial.println(" %");
      
      // DHT11 sampling rate is 1HZ.
      delay(1000);

      // comunicazione motore
      if((int)temperature > threshold && (int)temperature <= MAXTEMP){
              
              //calcolo velocità
              velocity = ((MAXVEL - MINVEL)/(MAXTEMP - threshold))*((int)temperature - threshold)^n   + MINVEL;
              Serial.print("accendo motore con Velocity:  "); Serial.println(velocity);
              
              //---PWM 
              digitalWrite(DIRA,HIGH); //one way
              digitalWrite(DIRB,LOW);
              //analogWrite(ENABLE,255); //enable on    // Caso in cui voglia velocità massima
              analogWrite(ENABLE,velocity); //half speed
             
        }
  
      if((int)temperature <= threshold || (int)temperature> MAXTEMP){
              Serial.println("spengo motore");
              //---PWM 
              digitalWrite(ENABLE,LOW); //enable off
              if((int)temperature> MAXTEMP){
                Serial.println("MAXTEMP SUPERATA - - - - - ERRORE");
                return;
              }
              
      }
 }



  
}
   
