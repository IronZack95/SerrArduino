// INIZIO PROGRAMMA
void setup() {
  // inizializzo Porta Seriale
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);
  
  // inizializzo righe e colonne LCD
  lcd.begin(2, 16);
  lcd.clear();
  
  // inizializzo Motore
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);

  // inizializzo Servo
  myservo.attach(SERVOPIN);
}
