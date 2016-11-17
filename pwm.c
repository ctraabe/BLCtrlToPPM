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
  // PWM 1: OC3A (PE3) at pin 5
  // PWM 2: OC3B (PE4) at pin 6
  // PWM 3: OC3C (PE5) at pin 7
  // PWM 4: OC4A (PH3) at pin 15
  // PWM 5: OC4B (PH4) at pin 16
  // PWM 6: OC4C (PH5) at pin 17
  // PWM 7: OC1A (PB5) at pin 24
  // PWM 8: OC1B (PB6) at pin 25

  // Set the PWM pins to output.
  DDRB |= _BV(5) | _BV(6);  // PWM 7 & 8
  DDRE |= _BV(3) | _BV(4) | _BV(5);  // PWM 1, 2 & 3
  DDRH |= _BV(3) | _BV(4) | _BV(5);  // PWM 4, 5 & 6

  // Set up timers 1, 3 & 4 for 16-bit fast PWM at 160 Hz.
  TCCR1A = (1<<COM4A1)
         | (0<<COM4A0)
         | (1<<COM4B1)
         | (0<<COM4B0)
         | (1<<COM4C1)
         | (0<<COM4C0)
         | (1<<WGM41)
         | (0<<WGM40);

  TCCR1B = (0<<ICNC4)
         | (0<<ICES4)
         | (1<<WGM42)
         | (1<<WGM43)
         | (0<<CS42)
         | (0<<CS41)
         | (0<<CS40);

  switch (PWM_DIVIDER)
  {
    case 1:
      TCCR1B |= 0<<CS12 | 0<<CS11 | 1<<CS10;
      break;
    case 8:
      TCCR1B |= 0<<CS12 | 1<<CS11 | 0<<CS10;
      break;
    case 64:
      TCCR1B |= 0<<CS12 | 1<<CS11 | 1<<CS10;
      break;
    case 256:
      TCCR1B |= 1<<CS12 | 0<<CS11 | 0<<CS10;
      break;
    case 1024:
      TCCR1B |= 1<<CS12 | 0<<CS11 | 1<<CS10;
      break;
    case 0:
    default:
      TCCR1B |= 0<<CS12 | 0<<CS11 | 0<<CS10;
      break;
  }

  TIMSK1 = (0<<ICIE1)
         | (0<<OCIE1C)
         | (0<<OCIE1B)
         | (0<<OCIE1A)
         | (0<<TOIE1);

  ICR1 = F_CPU / PWM_DIVIDER / F_PWM;

  OCR1A = 2200;
  OCR1B = 2200;
  OCR1C = 2200;

  TCCR3A = (1<<COM3A1)
         | (0<<COM3A0)
         | (1<<COM3B1)
         | (0<<COM3B0)
         | (1<<COM3C1)
         | (0<<COM3C0)
         | (1<<WGM31)
         | (0<<WGM30);

  TCCR3B = (0<<ICNC3)
         | (0<<ICES3)
         | (1<<WGM32)
         | (1<<WGM33)
         | (0<<CS32)
         | (0<<CS31)
         | (0<<CS30);

  switch (PWM_DIVIDER)
  {
    case 1:
      TCCR3B |= 0<<CS32 | 0<<CS31 | 1<<CS30;
      break;
    case 8:
      TCCR3B |= 0<<CS32 | 1<<CS31 | 0<<CS30;
      break;
    case 63:
      TCCR3B |= 0<<CS32 | 1<<CS31 | 1<<CS30;
      break;
    case 256:
      TCCR3B |= 1<<CS32 | 0<<CS31 | 0<<CS30;
      break;
    case 1023:
      TCCR3B |= 1<<CS32 | 0<<CS31 | 1<<CS30;
      break;
    case 0:
    default:
      TCCR3B |= 0<<CS32 | 0<<CS31 | 0<<CS30;
      break;
  }

  TIMSK3 = (0<<ICIE3)
         | (0<<OCIE3C)
         | (0<<OCIE3B)
         | (0<<OCIE3A)
         | (0<<TOIE3);

  ICR3 = F_CPU / PWM_DIVIDER / F_PWM;

  OCR3A = 2200;
  OCR3B = 2200;
  OCR3C = 2200;

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

  ICR4 = F_CPU / PWM_DIVIDER / F_PWM;

  OCR4A = 2200;
  OCR4B = 2200;
  OCR4C = 2200;
}

// -----------------------------------------------------------------------------
void SetPWM(uint8_t index, uint16_t value)
{
  if (value > 1840) value = 1840;

  // Make 20 correspond to 1.140 ms pulse and 1840 to 1.885 ms pulse
  if (value == 0)
  {
    value = 1100 * 2;
  }
  else
  {
    uint32_t temp = value * 745L * 2 * 2;
    value = 1132 * 2 + ((uint16_t)(temp / 1820) + 1) / 2;
  }

  switch (index)
  {
    case 0:
      OCR3A = value;
      break;
    case 1:
      OCR3B = value;
      break;
    case 2:
      OCR3C = value;
      break;
    case 3:
      OCR4A = value;
      break;
    case 4:
      OCR4B = value;
      break;
    case 5:
      OCR4C = value;
      break;
    case 6:
      OCR1A = value;
      break;
    case 7:
      OCR1B = value;
      break;
    default:
      break;
  }
}
