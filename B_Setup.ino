// INIZIO PROGRAMMA
void setup() {
    
  // inizializzo Porta Seriale
  Serial.begin(9600);

  Setup_Serial_div();

  //Inizialize Encoder
  pinMode(PinCLK,INPUT);
  pinMode(PinDT,INPUT);  
  pinMode(PinSW,INPUT);
  digitalWrite(PinSW, HIGH); // Pull-Up resistor for switch

  //Inizializzo Interrupt
  attachInterrupt (0,isr,FALLING); // interrupt 0 always connected to pin 2 on Arduino UNO

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);
    
  // inizializzo Motore
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);

  // inizializzo righe e colonne LCD
  lcd.begin(2, 16);
  lcd.clear();
  
  // inizializzo Servo
  myservo.attach(SERVOPIN);

  Setup_Serial_div();

}
