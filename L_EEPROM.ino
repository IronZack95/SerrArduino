/*
EEPROM.write(address, value)  Write a byte to the EEPROM.
EEPROM.read(address)          Reads a byte from the EEPROM. Locations that have never been written to have the value of 255.
EEPROM.get(address, data)     Read any data type or object from the EEPROM.
EEPROM.put(address, data)     Write any data type or object to the EEPROM.
EEPROM.update(address, value) Write a byte to the EEPROM. The value is written only if differs from the one already saved at the same address.
EEPROM[address]               This operator allows using the identifier `EEPROM` like an array. EEPROM cells can be read and written directly using this method.
*/
/*
const char string_0[] PROGMEM = "String 0"; // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "String 1";
const char string_2[] PROGMEM = "String 2";
const char string_3[] PROGMEM = "String 3";
const char string_4[] PROGMEM = "String 4";
const char string_5[] PROGMEM = "String 5";

const char *const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5};

char buffer[30];  // make sure this is large enough for the largest string it must hold
*/
/*
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));  // Necessary casts and dereferencing, just copy.
    Serial.println(buffer);
 */


void EEPROM_Clean(){
      //Cancella la eeprom dall'inizio fino all'address lunghezza
      for (int i = 0 ; i < MAXVAR-1 ; i++) {
          EEPROM.update(int_table_Address[i], 0);
      }
      
      Serial.println("EEPROM CLEAN - DONE"); 
      return;

  }

void EEPROM_Scan(){
      Serial.println("EEPROM Scan");
      for (int i = 0 ; i < MAXVAR-1 ; i++) {
          byte value = EEPROM.read(int_table_Address[i]);

          Serial.print(int_table_Address[i]);
          Serial.print("\t");
          Serial.print(value);
          Serial.println();
         
          if (i == EEPROM.length())
            i = 0;
      }
      return;
  }

void EEPROM_RAM_ResetToDefault(){
      byte int_table_1[] = {TH,MAXTEMP,MINTEMP,MINUMID,MAXUMID,PERVENT,DURVENT,MATNSTRT_H,MATNSTRT_M,SERASTRT_H,SERASTRT_M,DURIRRIG_H,DURIRRIG_M,PERIRGZFIX,DURIRGZFIX};
      //ripulisco fino a dove mi serve
      EEPROM_Clean();
      // update fino a dove mi serve
      for (int i = 0; i <= MAXVAR-1; i++){
        EEPROM.update(int_table_Address[i], int_table_1[i]);
        int_table[i] = int_table_1[i];
      }
      return;

      Serial.println("ResetToDefault"); 
  }
  
void  EEPROM_to_RAM_Update(){
       Serial.println("RAM Update");
       for (int i = 0 ; i < MAXVAR-1 ; i++) {
          if(int_table[i] != EEPROM.read(int_table_Address[i])){
              int_table[i] = EEPROM.read(int_table_Address[i]); 
          }
       }      
      return;
  }

void  RAM_to_EEPROM_Update(){
       Serial.println("EEPROM Update");
       for (int i = 0; i <= MAXVAR-1; i++)
        EEPROM.update(int_table_Address[i], int_table[i]);
   
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
