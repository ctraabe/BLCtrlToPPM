#include "main.h"

#include <avr/interrupt.h>
#include <avr/io.h>

// Instantiate Arduino constants
#define ARDUINO_MAIN
#include "arduino.h"

#include "i2c.h"
#include "led.h"
#include "ppm.h"
#include "timer0.h"
#include "uart.h"


int16_t main(void)
{
  LEDInit();
  Timer0Init();
  PPMInit();
  I2CSlaveInit();
  UARTInit();

  sei();  // Enable interrupts

  // Main loop
  uint16_t timer = GetTimestampMillisFromNow(250);
  for (;;)  // Preferred over while(1)
  {
    volatile struct I2CMessage * i2c_message_ptr = PopI2CMessage();
    if (i2c_message_ptr)
    {
      SetPPM(i2c_message_ptr->address, i2c_message_ptr->payload[0] << 3);
    }

    if (TimestampInPast(timer))
    {
      timer += 500;
      GreenLEDToggle();
    }
  }
}
