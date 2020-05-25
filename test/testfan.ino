#define ENABLE 5
 #define analogPin A3

int i;
 int s;
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("One way");
    digitalWrite(ENABLE,HIGH);
    leggo();
    delay(2000);
    digitalWrite(ENABLE,LOW);
    leggo();
    delay(1000);
    Serial.println("Reverse");
    digitalWrite(ENABLE,HIGH); 
    leggo();

    delay(2000);
    Serial.println("PWM full then slow");
    //---PWM example, full speed then slow
    analogWrite(ENABLE,255); //enable on

    for (i=255;i>0;i--){
      Serial.println((int)i);
      analogWrite(ENABLE,i);
      leggo();
      delay(500);
      }
    Serial.println("stop");
    delay(2000);
    digitalWrite(ENABLE,LOW);
    
}

void leggo(){
  s = analogRead(analogPin);  // read the input pin

  Serial.print("signal: "); Serial.println((int)s);
  
  
  
  }
