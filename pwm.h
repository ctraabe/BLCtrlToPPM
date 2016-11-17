#ifndef _PWM_H
#define _PWM_H

#include <inttypes.h>


// =============================================================================
// Public functions:

void PWMInit(void);

// -----------------------------------------------------------------------------
void SetPWM(uint8_t index, uint16_t value);


#endif  // _PWM_H
