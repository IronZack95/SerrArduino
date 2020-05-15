// -------------------------------LIBRERIE---------------------------------

#include <SimpleDHT.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Wire.h>
#include <DS3231.h>
#include <EEPROM.h>
#include <avr/pgmspace.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
// define pin
#define ENABLE    5
#define DIRA      3
#define DIRB      4
#define LIGHTPIN  0
#define pinDHT11  13
#define SERVOPIN  6
#define PinCLK    2
#define PinDT     15
#define PinSW     16

// define Error
#define OK        0
#define ERR_DHT   1
#define ERR_LIGHT 2

SimpleDHT11 dht11;

// Definizioni Globali Modificabili da Menù
#define TH            24          // gradi a cui si attiva la ventola
#define MAXTEMP       30          // grado limite a cui da errore
#define MINTEMP       10          // minima temperatura per il riscaldamento
#define MINUMID       26          // Umidità minima
#define MAXUMID       28          // Umidità massima
#define PERVENT       10          // Periodo di tempo in cui avviene la ventilazione
#define DURVENT       2           // Durata di tempo per cui avviene la ventilazione
#define MATNSTRT_H    06          // Start irrigazione mattina   Prime due cifre ora seconde due cifre minuto
#define MATNSTRT_M    00          // Start irrigazione mattina   Prime due cifre ora seconde due cifre minuto
#define SERASTRT_H    20          // Start irrigazione sera      Prime due cifre ora seconde due cifre minuto
#define SERASTRT_M    30          // Start irrigazione sera      Prime due cifre ora seconde due cifre minuto
#define DURIRRIG_H    01          // Durata irrigazione        Prime due cifre ora seconde due cifre minuto
#define DURIRRIG_M    35          // Durata irrigazione        Prime due cifre ora seconde due cifre minuto
#define PERIRGZFIX    15          // Periodo di tempo in cui avviene la irrigazione
#define DURIRGZFIX    1           // Durata di tempo per cui avviene la irrigazione

// Indirizzi in EEPROM
#define Address_TH            0         
#define Address_MAXTEMP       1        
#define Address_MINTEMP       2          
#define Address_MINUMID       3         
#define Address_MAXUMID       4         
#define Address_PERVENT       5        
#define Address_DURVENT       6      
#define Address_MATNSTRT_H    7        
#define Address_MATNSTRT_M    8      
#define Address_SERASTRT_H    9       
#define Address_SERASTRT_M    10        
#define Address_DURIRRIG_H    11        
#define Address_DURIRRIG_M    12      
#define Address_PERIRGZFIX    13    
#define Address_DURIRGZFIX    14 

//Variabili modificabili nella RAM
byte int_table[] = {TH,MAXTEMP,MINTEMP,MINUMID,MAXUMID,PERVENT,DURVENT,MATNSTRT_H,MATNSTRT_M,SERASTRT_H,SERASTRT_M,DURIRRIG_H,DURIRRIG_M,PERIRGZFIX,DURIRGZFIX};
byte int_table_Address[] = {Address_TH,Address_MAXTEMP,Address_MINTEMP,Address_MINUMID,Address_MAXUMID,Address_PERVENT,Address_DURVENT,Address_MATNSTRT_H,Address_MATNSTRT_M,Address_SERASTRT_H,Address_SERASTRT_M,Address_DURIRRIG_H,Address_DURIRRIG_M,Address_PERIRGZFIX,Address_DURIRGZFIX};
const short MAXVAR = sizeof(int_table_Address);
//byte *const int_table[] PROGMEM = {TH,MAXTEMP,MINTEMP,MINUMID,MAXUMID,PERVENT,DURVENT,MATNSTRT_H,MATNSTRT_M,SERASTRT_H,SERASTRT_M,DURIRRIG_H,DURIRRIG_M,PERIRGZFIX,DURIRGZFIX};

// Definizioni costanti Globali
#define rapporto      1           // rapporto della curva
#define MAXVEL        255         // massima velocità
#define MINVEL        100         // minima velocità
#define MAXLIGHT      1024        // massimo valore codifica luce
#define MINSERVO      0           // Servo in posizione zero gradi
#define MAXSERVO      180.        // massimo range servomotore 0 - 180

//  Vaiabili di servizio
#define TimeImpulsiAvvio  100     // PERIODO impulsi per avviare il motore
#define ImpulsiAvvio  200         // velocità istantanea per avviare il motore
#define CicliAvvio    2           // Numero cicli di impulsi per avviare il motore

// Variabili Tempo
#define ATTESAMENU    10          // Secondi in cui il menù rimane attivo
#define AUTOMATIC_SAMPLING_RATE   1000      //SAMPLING RATE
#define UI_SAMPLING_RATE          100 
int skip = 0;                      // contatore che permette l'automazione
int del = AUTOMATIC_SAMPLING_RATE; // SAMPLING RATE 


// create servo object to control a servo
Servo myservo;  // twelve servo objects can be created on most boards

// create Clock Object
DS3231 clock;
RTCDateTime dt;


// Variabili DHT11
byte temperature = 0;
byte humidity = 0; 

// Variabili fotocella
int light = 0;
int light_percentuale = 0;

// Variabili Motore
float velocity = 0;
int   velocity_percentuale = 0;
bool  direzione = true;          // true = avanti false = indietro

// Variabili Servo
int ultima_posizione = 0;
int posizione = 0;

//Variabili RTC Clock
volatile unsigned long Last_Unix_time = 0;
//Variabili Interruprs
volatile boolean TurnDetected;  // need volatile for Interrupts
volatile boolean rotationdirection;  // CW or CCW rotation

//USER INTERFACE
volatile boolean UI_Status = false;
int   page = 0;
int   last_page = 0;
byte  last_temperature = 0;
int   last_light_percentuale = 0;
bool  Mod = false;             //consente la modifica



//Variabili Encoder
int RotaryPosition=0;
int PrevPosition;           // Previous Rotary position Value to check accuracy
int StepsToTake;            // How much to move Stepper
bool Button = false;

//Custom char

byte gradi[8] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte alien[8] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};

byte plant[8] = {
  B00000,
  B01000,
  B10001,
  B01010,
  B00100,
  B00010,
  B00100,
  B01110
};

// pagina 0
const char string_0[] PROGMEM = "Temp:    C      "; // "String N" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "TH:     MAX:    ";
// pagina 1
const char string_2[] PROGMEM = "Riscaldamento:  "; 
const char string_3[] PROGMEM = "MIN:     C      ";
// pagina 2
const char string_4[] PROGMEM = "Umidita':     % "; 
const char string_5[] PROGMEM = "MIN:    MAX:    ";
// pagina 3
const char string_6[] PROGMEM = "Ventilazione:   ";
const char string_7[] PROGMEM = "Ogni:    minuti ";
// pagina 4
const char string_8[] PROGMEM = "Ventilazione:   ";
const char string_9[] PROGMEM = "Per:     minuti ";
// pagina 5
const char string_10[] PROGMEM = "Irrigazione: ore";
const char string_11[] PROGMEM = "M   :   S   :   ";
// pagina 6
const char string_12[] PROGMEM = "Irrigazione: per";
const char string_13[] PROGMEM = "   ore e    min ";
// pagina 7
const char string_14[] PROGMEM = "Irrigazione: fix";
const char string_15[] PROGMEM = "Ogni:    minuti ";
// pagina 8
const char string_16[] PROGMEM = "Irrigazione: fix";
const char string_17[] PROGMEM = "Per:     minuti ";
// pagina 9
const char string_18[] PROGMEM = "Illuminazione:  ";
const char string_19[] PROGMEM = "Stato:    %     "; 
// pagina 10
const char string_20[] PROGMEM = "----MODIFICA----";
const char string_21[] PROGMEM = "    Premi OK    ";
// pagina 11
const char string_22[] PROGMEM = "-----USCITA-----";
const char string_23[] PROGMEM = "    Premi OK    ";



const char *const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8,string_9, string_10, string_11, string_12, string_13,string_14, string_15, string_16, string_17, string_18, string_19, string_20, string_21, string_22,string_23};
const int MAXPAGE = sizeof(string_table)/4;


//-------------------------------INIZIO PROGRAMMA--------------------------------
