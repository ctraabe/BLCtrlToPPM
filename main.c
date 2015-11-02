#include "main.h"

#include <avr/interrupt.h>
#include <avr/io.h>

// Instantiate Arduino constants
#define ARDUINO_MAIN
#include "arduino.h"

#include "ppm.h"
#include "timer0.h"


int16_t main(void)
{
  ARDUINO_LED_ENABLE;
  Timer0Init();
  PPMInit();

  sei();  // Enable interrupts

  // Main loop
  uint16_t timer = GetTimestampMillisFromNow(250), counter = 0;
  for (;;)  // Preferred over while(1)
  {
    counter > 2000 ? counter = 0 : counter++;
    SetPPM(6, counter);
    SetPPM(7, counter);
    SetPPM(8, counter);
    while(!TimestampInPast(timer)) continue;
    timer += 1;
    ARDUINO_LED_TOGGLE;
  }
}
