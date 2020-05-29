// INIZIO PROGRAMMA

void setup() {

  // inizializzo Porta Seriale
  Serial.begin(9600);
  
  Setup_Serial_div();
  Setup_Serial();

  //carico nella RAM i valori dall'EEPROM
  EEPROM_to_RAM_Update();

  //Inizializzo EEPROM
  //EEPROM_RAM_ResetToDefault();            // <---- Decommento se voglio Le Impostazioni di fabbrica
  EEPROM_Scan();                          // <---- Decommento se voglio lo scan inSerial Monitor della EEPROM
  
  // Initialize DS3231
  Serial.println("Initialize DS3231");
  clock.begin();

  //Set Allarms
  clock.armAlarm1(false);
  clock.armAlarm2(false);
  clock.clearAlarm1();
  clock.clearAlarm2();
  
  // Inizialize TIME
  //clock.setDateTime(__DATE__, __TIME__);      //<---- uncomment only for clock reset and reupload

  // Set Alarm - Every second.
  // DS3231_EVERY_SECOND is available only on Alarm1.
  // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)
  clock.setAlarm1(0, 0, 0, 0, DS3231_EVERY_SECOND);

  // Set Alarm - Every full minute.
  // DS3231_EVERY_MINUTE is available only on Alarm2.
  // setAlarm2(Date or Day, Hour, Minute, Second, Mode, Armed = true)
  clock.setAlarm2(0, 0, 0, DS3231_EVERY_MINUTE);


  //Inizialize Encoder
  pinMode(PinCLK,INPUT);
  pinMode(PinDT,INPUT);  
  pinMode(PinSW,INPUT);
  digitalWrite(PinSW, HIGH); // Pull-Up resistor for switch     // Perchè sto usando gli ingressi analogici come digitali
  digitalWrite(PinDT, HIGH); // Pull-Up resistor for switch

  //Inizializzo Interrupt
  attachInterrupt (0,isr,FALLING); // interrupt 0 always connected to pin 2 on Arduino UNO

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
    
  // Inizialize Motore
  pinMode(ENABLE,OUTPUT);

  // Inizialize RELE'
  pinMode(RELAY,OUTPUT);
  Relay(false);
/*
  // Inizialisso IR
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
*/
  // Inizialize righe e colonne LCD
  lcd.begin(2, 16);
  lcd.clear();
  Setup_LCD();
  
  // Inizialize Servo
  myservo.attach(SERVOPIN);

  //Custom Char   Se dovessero servire
  lcd.createChar(0, gradi);
  /*
  lcd.createChar(1, alien);
  lcd.createChar(2, plant);
  */
  //inizializzo servo
  //last_irrig_fix = (int)dt.minute + 60*(int)dt.hour;
  InterruttoreServo(false);   // chiudo
  //GestioneIrrigazione();

  Setup_Serial_div();
  delay(ATTESASETUP);
  
}
