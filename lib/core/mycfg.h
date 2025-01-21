//Attiny GPIO Pins
#define LED_att85  1 // 1
#define BUZZER     0 // 0
#define TRIG_PIN   4 // 0 4 2 <- OK   NOK -> 4 5 4 3 3
#define ECHO_PIN   2 // 2 2 3 <- OK   NOK -> 5 4 3 4 2


//ESP GPIO Pins
//#define LED_att85  2 // 2
//#define BUZZER    15 // 0
//#define TRIG_PIN   5 // 5
//#define ECHO_PIN   4 // 4


// Battery & Voltage
#define Batt_Max 5500                 // Battery Highest voltage.  [mv]
#define Batt_Min 4600                 // Battery lowest voltage.   [mv]
#define VADC_MAX 5000                 // Maximum ADC Voltage input [mv]


// Beeps
int N_beeps_Max = 3;                            // Max number of Beeps (per cycle)  Recomended = 6

/*
// Distances
unsigned int Max_Dist = 300;                    // Max distance considered to be measured (it beeps 1 slot per cycle if less than this)
unsigned int High_Dist = 220;                   // Highest distance (it beeps 2 slots per cycle if less than this)
unsigned int Midd_Dist = 180;                   // Middle distance (it beeps all slots per cycle if less than this)
unsigned int Short_Dist = 160;                  // Short distance (Continous beeps if less than this)
unsigned int Min_Dist = 40;                     // Min distance considered to be a distance measure (less than this will be a gesture command)
*/

// Distances (Corona Virus 1m distance)
unsigned int Max_Dist = 130;                    // Max distance considered to be measured (it beeps 1 slot per cycle if less than this)
unsigned int High_Dist = 120;                   // Highest distance (it beeps 2 slots per cycle if less than this)
unsigned int Midd_Dist = 110;                   // Middle distance (it beeps all slots per cycle if less than this)
unsigned int Short_Dist = 100;                  // Short distance (Continous beeps if less than this)
unsigned int Min_Dist = 40;                     // Min distance considered to be a distance measure (less than this will be a gesture command)

// Timers
unsigned long TIMEOut = 20000;                  // HCSR04 Sensor measuring Time Out
unsigned long time_betw = 75;                   // 60ms is the minimum time between measurements (confirmed with datasheet?)
unsigned long LED_millis = 200;                 // LED Flash period (ON + OFF time)
unsigned long BUZZER_millis = 200;              // Buzz beeps period (ON + OFF time)
unsigned long Cycle_millis = N_beeps_Max * LED_millis;    // Cycle = "N_beeps_Max" slots  x  N_beeps Period
unsigned long Overall_millis = 15000;           // Sensor will run while on the same distance for this X miliseconds
                                                // (it would mean that the car had parked there) 

