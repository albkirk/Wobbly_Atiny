// Variables
float voltage = 0.0;                                    // Input Voltage [v]
float Batt_Level = 100.0;                               // Battery level [0%-100%]

// Timers for millis used on Sleeping and LED flash
unsigned long now_millis=0;
bool beeping = false;


// Functions
long readVcc() {
  // Read 1.1V reference against AVcc
  // set the reference to Vcc and the measurement to the internal 1.1V reference
  #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
    ADMUX = _BV(MUX5) | _BV(MUX0);
  #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    ADMUX = _BV(MUX3) | _BV(MUX2);
  #else
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #endif  
 
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA,ADSC)); // measuring
 
  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
  uint8_t high = ADCH; // unlocks both
 
  long result = (high<<8) | low;
 
  result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
  return result; // Vcc in millivolts
}


void flash_LED(unsigned int n_flash = 1, unsigned long pausa = LED_millis) {
    if (LED_att85>=0) {
        for (size_t i = 0; i < n_flash; i++) {
            digitalWrite(LED_att85, HIGH);              // Turn LED on
            delay(pausa/2);
            digitalWrite(LED_att85, LOW);               // Turn LED off
            delay(pausa/2);
        }
    }
}

void Buzz(unsigned int n_beeps = 1, unsigned long pausa = BUZZER_millis) {
    if (BUZZER>=0) {
        for (size_t i = 0; i < n_beeps; i++) {
            digitalWrite(BUZZER, HIGH);                 // Turn Buzzer on
            delay(pausa/2);
            digitalWrite(BUZZER, LOW);                  // Turn Buzzer off
            delay(pausa/2);
        }
    }
}

void flash_Buzz(unsigned int n_flash = 1, unsigned long pausa = LED_millis) {
    if (LED_att85>=0) {
        digitalWrite(BUZZER, HIGH);                     // Turn Buzzer on
        for (size_t i = 0; i < n_flash; i++) {
            digitalWrite(LED_att85, HIGH);              // Turn LED on and Buzzer off
            delay(pausa/2);
            digitalWrite(LED_att85, LOW);               // Turn LED off and Buzzer on
            delay(pausa/2);
        }
        digitalWrite(BUZZER, LOW);                      // Turn Buzzer off

    }
}

void LED_BUZ(int slot) {                                // slot range 1 to N_beeps_Max
    now_millis = millis() % Cycle_millis;
    beeping = false;
    for (int i = 1; i <= slot; i++) {
        if (now_millis > LED_millis*(i-1) && now_millis < LED_millis*i-LED_millis/2 ) {
            if (LED_att85>=0) digitalWrite(LED_att85, HIGH);   // toggles LED status. will be restored by hw_loop function below
            if (BUZZER>=0) digitalWrite(BUZZER, LOW);   // toggles Buzzer status. will be restored by hw_loop function below
            beeping = true;
//            delay(LED_millis/2);
            break;
        }
        else if (now_millis > LED_millis*i-LED_millis/2 && now_millis < LED_millis*i ) {
            if (LED_att85>=0) digitalWrite(LED_att85, LOW);   // toggles LED status. will be restored by hw_loop function below
            if (BUZZER>=0) digitalWrite(BUZZER, HIGH);   // toggles Buzzer status. will be restored by hw_loop function below
            beeping = true;
//            delay(LED_millis/2);
            break;
        }
    }
    if (beeping == false) {
            if (LED_att85>=0) digitalWrite(LED_att85, LOW);   // toggles LED status. will be restored by hw_loop function below
            if (BUZZER>=0) digitalWrite(BUZZER, LOW);   // toggles Buzzer status. will be restored by hw_loop function below
    }
}


void hw_setup() {
  // Output GPIOs
        if (LED_att85>=0) {
            pinMode(LED_att85, OUTPUT);
            digitalWrite(LED_att85, LOW);                   // initialize LED
        }
        if (BUZZER>=0)  {
            pinMode(BUZZER, OUTPUT);
            digitalWrite(BUZZER, LOW);                      // initialize Buzzer
        }

        //pinMode(0, INPUT_PULLUP);                           // initialize unused PIN to reduce power consumption
        //pinMode(1, INPUT_PULLUP);                           // initialize unused PIN to reduce power consumption
        //pinMode(2, INPUT_PULLUP);                           // initialize unused PIN to reduce power consumption
        pinMode(3, INPUT_PULLUP);                           // initialize unused PIN to reduce power consumption
        //pinMode(4, INPUT_PULLUP);                           // initialize unused PIN to reduce power consumption
        pinMode(5, INPUT_PULLUP);                           // initialize unused PIN to reduce power consumption

  // Input GPIOs

}

void hw_loop() {
  // LED and Buzzer handling in loop function
      if (LED_att85>=0) digitalWrite(LED_att85, LOW);
      if (BUZZER>=0) digitalWrite(BUZZER, LOW);
}