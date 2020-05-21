#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("One way");
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    delay(2000);
    digitalWrite(ENABLE,LOW);
    delay(1000);
    Serial.println("Reverse");
    digitalWrite(ENABLE,HIGH); 
    digitalWrite(DIRA,LOW);  // direzione correttta
    digitalWrite(DIRB,HIGH);
    delay(2000);
    Serial.println("PWM full then slow");
    //---PWM example, full speed then slow
    analogWrite(ENABLE,255); //enable on
     digitalWrite(DIRA,LOW);  // direzione correttta
    digitalWrite(DIRB,HIGH);
    for (i=255;i>0;i--){
      Serial.println((int)i);
      analogWrite(ENABLE,i);
      delay(500);
      }
    Serial.println("stop");
    delay(2000);
    digitalWrite(ENABLE,LOW);
    
}
