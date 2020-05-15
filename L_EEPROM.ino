/*
EEPROM.write(address, value)  Write a byte to the EEPROM.
EEPROM.read(address)          Reads a byte from the EEPROM. Locations that have never been written to have the value of 255.
EEPROM.get(address, data)     Read any data type or object from the EEPROM.
EEPROM.put(address, data)     Write any data type or object to the EEPROM.
EEPROM.update(address, value) Write a byte to the EEPROM. The value is written only if differs from the one already saved at the same address.
EEPROM[address]               This operator allows using the identifier `EEPROM` like an array. EEPROM cells can be read and written directly using this method.
*/

void EEPROM_Clean(){
      //Cancella tuttal la eeprom
      for (int i = 0 ; i < EEPROM.length() ; i++) {
          EEPROM.update(i, 0);
      }
      
      Serial.println("EEPROM CLEAN - DONE"); 
      return;

  }

void EEPROM_Scan(){
      //Iterate the EEPROM using a for loop.

      for (int index = 0 ; index < EEPROM.length() ; index++) {
          //Add one to each cell in the EEPROM
          EEPROM[ index ] += 1;
      }

      Serial.println("EEPROM CLEAN - DONE"); 
      return;
  }

  

























/*
// save some unsigned ints
const PROGMEM uint16_t charSet[] = { 65000, 32796, 16843, 10, 11234};

// save some chars
const char signMessage[] PROGMEM = {"I AM PREDATOR,  UNSEEN COMBATANT. CREATED BY THE UNITED STATES DEPART"};

unsigned int displayInt;
char myChar;


void setup() {
  Serial.begin(9600);
  while (!Serial);  // wait for serial port to connect. Needed for native USB

  // put your setup code here, to run once:
  // read back a 2-byte int
  for (byte k = 0; k < 5; k++) {
    displayInt = pgm_read_word_near(charSet + k);
    Serial.println(displayInt);
  }
  Serial.println();

  // read back a char
  for (byte k = 0; k < strlen_P(signMessage); k++) {
    myChar = pgm_read_byte_near(signMessage + k);
    Serial.print(myChar);
  }

  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
}

*/
