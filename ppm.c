#include "ppm.h"

#include <avr/io.h>

#include "arduino.h"


// =============================================================================
// Private data:

#define PPM_DIVIDER (8)
#define F_PPM (160)


// =============================================================================
// Public functions:

void PPMInit(void)
{
  // Arduino MEGA 2560 specifics
  // PWM2  - TIMER3B (16 bit) pin PE4
  // PWM3  - TIMER3C (16 bit) pin PE5
  // PWM4  - TIMER0B (8 bit) pin PG5
  // PWM5  - TIMER3A (16 bit) pin PE3
  // PWM6  - TIMER4A (16 bit) pin PH3
  // PWM7  - TIMER4B (16 bit) pin PH4
  // PWM8  - TIMER4C (16 bit) pin PH5
  // PWM9  - TIMER2B (8 bit) pin PH6
  // PWM10 - TIMER2A (8 bit) pin PB4
  // PWM11 - TIMER1A (16 bit) pin PB5
  // PWM12 - TIMER1B (16 bit) pin PB6
  // PWM13 - TIMER0A (8 bit) pin PB7

  // For demonstration, use pins 6, 7, and 8

  PinMode(6, OUTPUT);
  PinMode(7, OUTPUT);
  PinMode(8, OUTPUT);

  TCCR4A = (1<<COM4A1)
         | (0<<COM4A0)
         | (1<<COM4B1)
         | (0<<COM4B0)
         | (1<<COM4C1)
         | (0<<COM4C0)
         | (1<<WGM41)
         | (0<<WGM40);

  TCCR4B = (0<<ICNC4)
         | (0<<ICES4)
         | (1<<WGM42)
         | (1<<WGM43)
         | (0<<CS42)
         | (0<<CS41)
         | (0<<CS40);

  switch (PPM_DIVIDER)
  {
    case 1:
      TCCR4B |= 0<<CS42 | 0<<CS41 | 1<<CS40;
      break;
    case 8:
      TCCR4B |= 0<<CS42 | 1<<CS41 | 0<<CS40;
      break;
    case 64:
      TCCR4B |= 0<<CS42 | 1<<CS41 | 1<<CS40;
      break;
    case 256:
      TCCR4B |= 1<<CS42 | 0<<CS41 | 0<<CS40;
      break;
    case 1024:
      TCCR4B |= 1<<CS42 | 0<<CS41 | 1<<CS40;
      break;
    case 0:
    default:
      TCCR4B |= 0<<CS42 | 0<<CS41 | 0<<CS40;
      break;
  }

  TIMSK4 = (0<<ICIE4)
         | (0<<OCIE4C)
         | (0<<OCIE4B)
         | (0<<OCIE4A)
         | (0<<TOIE4);

  ICR4 = F_CPU / PPM_DIVIDER / F_PPM;
  OCR4A = 2200;
  OCR4B = 2200;
  OCR4C = 2200;
}

// -----------------------------------------------------------------------------
void SetPPM(uint8_t index, uint16_t value)
{
  if (value > 1680) value = 1680;
  switch (index)
  {
    case 6:
      OCR4A = 2200 + value;
      break;
    case 7:
      OCR4B = 2200 + value;
      break;
    case 8:
      OCR4C = 2200 + value;
      break;
    default:
      break;
  }
}
