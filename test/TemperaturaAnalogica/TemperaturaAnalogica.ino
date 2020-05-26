#define ANLGTMP   17
#define MAXADC    1024
int Analog_Temp = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Lettura_Temperatura();
  delay(500);
}

int Lettura_Temperatura(){      // lettura sensore temperatura analogico
      Analog_Temp  = analogRead(ANLGTMP);
      Serial.print("Analog_Temp: "); Serial.println(Analog_Temp);
      double tempK = log(10000.0 * ((1024.0 / Analog_Temp - 1)));
      tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
      Serial.print("Kelvin: "); Serial.println(tempK);
      float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
      Serial.print("Celsius: "); Serial.println(tempC);
      float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
      Serial.print("Fahrenheit: "); Serial.println(tempF);
      Serial.println("---------------------------------------");
      return;
  }
