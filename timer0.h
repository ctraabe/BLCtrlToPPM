#ifndef _TIMER0_H
#define _TIMER0_H

#include <inttypes.h>


// =============================================================================
// Public functions:

// This function initializes TIMER1 and TIMER3. This timer trigger interrupts
// at 1 kHz and 128 Hz respectively.
void Timer0Init(void);

// -----------------------------------------------------------------------------
// This function returns the current timestamp.
uint16_t GetTimestamp(void);

// -----------------------------------------------------------------------------
// This function returns a timestamp corresponding to "t" ms in the future. This
// timestamp can be checked against the current timestamp to see if a certain
// amount of time has passed. This function works for durations up to 32767 ms.
uint16_t GetTimestampMillisFromNow(uint16_t t);

// -----------------------------------------------------------------------------
// This function compares a timestamp to the current timestamp and returns TRUE
// if the timestamp is in the past. This function works for durations up to
// 32767 ms.
uint8_t TimestampInPast(uint16_t t);

// -----------------------------------------------------------------------------
// This function returns the amount of time that has elapsed since the timestamp
// "t" has occurred. This function works for time periods up to 65535 ms.
uint16_t MillisSinceTimestamp(uint16_t t);

// -----------------------------------------------------------------------------
// This function delays execution of the program for "t" ms. Functions triggered
// by interrupts will still execute during this period. This function works for
// time periods up to 32767 ms.
void Wait(uint16_t w);


#endif  // _TIMER0_H
