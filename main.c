#include "main.h"

#include <avr/interrupt.h>
#include <avr/io.h>

// Instantiate Arduino constants
#define ARDUINO_MAIN
#include "arduino.h"

#include "ppm.h"
#include "timer0.h"
#include "uart.h"


int16_t main(void)
{
  ARDUINO_LED_ENABLE;
  Timer0Init();
  PPMInit();
  UARTInit();

  sei();  // Enable interrupts

  // Main loop
  uint16_t timer = GetTimestampMillisFromNow(250);
  for (;;)  // Preferred over while(1)
  {
    while(!TimestampInPast(timer)) continue;
    UARTPrintf("Test");
    timer += 500;
    ARDUINO_LED_TOGGLE;
  }
}
