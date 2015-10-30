#include "pwm.h"

#include <avr/io.h>

#include "arduino.h"


// =============================================================================
// Private data:

#define PWM_DIVIDER (8)
#define F_PWM (160)


// =============================================================================
// Public functions:

void PWMInit(void)
{
  *portModeRegister(digitalPinToPort(6)) |= digitalPinToBitMask(6);
  *portModeRegister(digitalPinToPort(7)) |= digitalPinToBitMask(7);
  *portModeRegister(digitalPinToPort(8)) |= digitalPinToBitMask(8);

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

  switch (PWM_DIVIDER)
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

  ICR4 = F_CPU / PWM_DIVIDER / F_PWM;  // Output compare register.
  OCR4A = 3000;
  OCR4B = 3000;
  OCR4C = 3000;
}
