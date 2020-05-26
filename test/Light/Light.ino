#define LIGHTPIN 0
#define MAXADC 1024
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
      int light  = analogRead(LIGHTPIN);
      Serial.print("light:  "); Serial.println(light); 
      int light_percentuale = (int)abs(light)*(100./MAXADC);
      Serial.print("light percentuale:  "); Serial.println(light_percentuale); 
      Serial.println("---------------------------------");
      delay(500);
}
