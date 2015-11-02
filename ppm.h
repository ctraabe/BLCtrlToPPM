#ifndef _PWM_H
#define _PWM_H

#include <inttypes.h>


// =============================================================================
// Public functions:

void PPMInit(void);

// -----------------------------------------------------------------------------
void SetPPM(uint8_t index, uint16_t value);


#endif  // _PWM_H
