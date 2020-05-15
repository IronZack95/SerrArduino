// -------------------------------LIBRERIE---------------------------------

#include <SimpleDHT.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Wire.h>
#include <DS3231.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
// define pin
#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define LIGHTPIN 0
#define pinDHT11 13
#define SERVOPIN 6
#define PinCLK 2
#define PinDT 15
#define PinSW 16

// define Error
#define OK  0
#define ERR_DHT 1
#define ERR_LIGHT 2

SimpleDHT11 dht11;

// Definizioni Globali
#define threshold 24          // gradi a cui si attiva la ventola
#define MAXTEMP 30            // grado limite a cui da errore
#define MAXVEL 255            // massima velocità
#define MINVEL 100            // minima velocità
#define rapporto 1            // rapporto della curva
#define MAXLIGHT 1024         // massimo valore codifica luce
#define MAXSERVO 180.          //  massimo range servomotore 0 - 180
#define TimeImpulsiAvvio  100 // PERIODO impulsi per avviare il motore
#define ImpulsiAvvio  200     // velocità istantanea per avviare il motore
#define CicliAvvio  2         // Numero cicli di impulsi per avviare il motore


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
int velocity_percentuale = 0;
bool direzione = true; // true = avanti false = indietro

// Variabili Servo
int ultima_posizione = 0;
int posizione = 0;

//Variabili RTC Clock
//int Last_hour = 0;
//int Last_minute = 0;
//int Last_second = 0;

int hour = 0;
int minute = 0;
int second = 0;

//Variabili Interruprs
volatile boolean TurnDetected;  // need volatile for Interrupts
volatile boolean rotationdirection;  // CW or CCW rotation

//Variabili Encoder
int RotaryPosition=0;
int PrevPosition;     // Previous Rotary position Value to check accuracy
int StepsToTake;      // How much to move Stepper


//-------------------------------INIZIO PROGRAMMA--------------------------------
