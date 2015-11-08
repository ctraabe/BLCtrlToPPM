#ifndef I2C_H_
#define I2C_H_


#include <inttypes.h>


#define MAX_I2C_MESSAGE_LENGTH (8)

enum I2CError {
  I2C_ERROR_NONE = 0,
  I2C_ERROR_ACK,
  I2C_ERROR_NACK,
  I2C_ERROR_NO_REPLY,
  I2C_ERROR_OTHER,
  I2C_ERROR_BUSY,
};

struct I2CMessage {
  uint8_t address;
  uint8_t length;
  uint8_t payload[MAX_I2C_MESSAGE_LENGTH];
};


// =============================================================================
// Accessors

enum I2CError I2CError(void);

// -----------------------------------------------------------------------------
uint8_t I2CDataReceived(void);

// -----------------------------------------------------------------------------
volatile struct I2CMessage * PopI2CMessage(void);


// =============================================================================
// Public functions:

// This initialization sets the I2C pin states. It should be performed prior to
// enabling interrupts.
void I2CSlaveInit(void);


#endif  // I2C_H_
