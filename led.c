#include "led.h"


#include <avr/io.h>


// =============================================================================
// Private data:

#define BLUE_LED_DDR (DDRG)
#define GREEN_LED_DDR (DDRF)
#define YELLOW_LED_DDR (DDRF)

#define BLUE_LED_PORT (PORTG)
#define GREEN_LED_PORT (PORTF)
#define YELLOW_LED_PORT (PORTF)

#define BLUE_LED_1_PIN (_BV(3))
#define BLUE_LED_2_PIN (_BV(4))
#define GREEN_LED_PIN (_BV(7))
#define YELLOW_LED_1_PIN (_BV(6))
#define YELLOW_LED_2_PIN (_BV(5))


// =============================================================================
// Public functions:

void LEDInit(void)
{
  // Set LED pins to output.
  BLUE_LED_DDR |= BLUE_LED_1_PIN | BLUE_LED_2_PIN;
  GREEN_LED_DDR |= GREEN_LED_PIN;
  YELLOW_LED_DDR |= YELLOW_LED_1_PIN | YELLOW_LED_2_PIN;

  BlueLED1Off();
  BlueLED2Off();
  GreenLEDOff();
  YellowLED1Off();
  YellowLED2Off();
}

// -----------------------------------------------------------------------------
void BlueLED1Off(void)
{

  BLUE_LED_PORT &= ~BLUE_LED_1_PIN;
}

// -----------------------------------------------------------------------------
void BlueLED1On(void)
{
  BLUE_LED_PORT |= BLUE_LED_1_PIN;
}

// -----------------------------------------------------------------------------
void BlueLED1Toggle(void)
{
  BLUE_LED_PORT ^= BLUE_LED_1_PIN;
}

// -----------------------------------------------------------------------------
void BlueLED2Off(void)
{
  BLUE_LED_PORT &= ~BLUE_LED_2_PIN;
}

// -----------------------------------------------------------------------------
void BlueLED2On(void)
{
  BLUE_LED_PORT |= BLUE_LED_2_PIN;
}

// -----------------------------------------------------------------------------
void BlueLED2Toggle(void)
{
  BLUE_LED_PORT ^= BLUE_LED_2_PIN;
}

// -----------------------------------------------------------------------------
void GreenLEDOff(void)
{

  GREEN_LED_PORT &= ~GREEN_LED_PIN;
}

// -----------------------------------------------------------------------------
void GreenLEDOn(void)
{
  GREEN_LED_PORT |= GREEN_LED_PIN;
}

// -----------------------------------------------------------------------------
void GreenLEDToggle(void)
{
  GREEN_LED_PORT ^= GREEN_LED_PIN;
}

// -----------------------------------------------------------------------------
void YellowLED1Off(void)
{
  YELLOW_LED_PORT &= ~YELLOW_LED_1_PIN;
}

// -----------------------------------------------------------------------------
void YellowLED1On(void)
{
  YELLOW_LED_PORT |= YELLOW_LED_1_PIN;
}

// -----------------------------------------------------------------------------
void YellowLED1Toggle(void)
{
  YELLOW_LED_PORT ^= YELLOW_LED_1_PIN;
}

// -----------------------------------------------------------------------------
void YellowLED2Off(void)
{
  YELLOW_LED_PORT &= ~YELLOW_LED_2_PIN;
}

// -----------------------------------------------------------------------------
void YellowLED2On(void)
{
  YELLOW_LED_PORT |= YELLOW_LED_2_PIN;
}

// -----------------------------------------------------------------------------
void YellowLED2Toggle(void)
{
  YELLOW_LED_PORT ^= YELLOW_LED_2_PIN;
}
