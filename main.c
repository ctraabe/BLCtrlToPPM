#include "main.h"

#include <avr/interrupt.h>
#include <avr/io.h>

// Instantiate Arduino constants
#define ARDUINO_MAIN
#include "arduino.h"

#include "i2c.h"
#include "led.h"
#include "pwm.h"
#include "timer0.h"
#include "uart.h"


int16_t main(void)
{
  LEDInit();
  Timer0Init();
  PWMInit();
  I2CSlaveInit();
  UARTInit();

  sei();  // Enable interrupts

  // Main loop
  uint16_t heartbeat = GetTimestampMillisFromNow(250);
  uint16_t pwm_timeout[8] = { 0 };
  for (;;)  // Preferred over while(1)
  {
    volatile struct I2CMessage * i2c_message_ptr = PopI2CMessage();
    if (i2c_message_ptr && i2c_message_ptr->address < 8)
    {
      // Set the motor to the desired value.
      SetPWM(i2c_message_ptr->address,
        ((uint16_t)i2c_message_ptr->payload[0] << 3)
        | (i2c_message_ptr->payload[1] & 0x07));

      // Advance the timeout forward 100 ms.
      pwm_timeout[i2c_message_ptr->address] = GetTimestampMillisFromNow(100);
    }

    // Kill any motors that have stale data.
    for (uint8_t i = 8; i--; )
    {
      if (TimestampInPast(pwm_timeout[i])) SetPWM(i, 0);
    }

    if (TimestampInPast(heartbeat))
    {
      heartbeat += 250;
      GreenLEDToggle();
    }
  }
}
