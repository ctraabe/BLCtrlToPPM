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
