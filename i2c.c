// TODO: just turn this file into a BLCtrl conversion file. No need to go the
// trouble of separating functionality for this one-off application.

#include "i2c.h"

#include <avr/interrupt.h>
#include <util/twi.h>

#include "arduino.h"
#include "led.h"


// =============================================================================
// Private data:

#define BLCTRL_BASE_ADDRESS (0x52)
#define N_BUFFERS_POWER_OF_2 (4)  // 2^4 = 16
#define N_BUFFERS (1 << N_BUFFERS_POWER_OF_2)

volatile struct I2CMessage rx_buffer_[N_BUFFERS];
volatile uint8_t rx_buffer_head_ = 0;
uint8_t rx_buffer_tail_ = 0;
enum I2CError i2c_error_ = I2C_ERROR_NONE;


// =============================================================================
// Private function declarations:

static void I2CAck(void);


// =============================================================================
// Accessors

enum I2CError I2CError(void)
{
  return i2c_error_;
}

// -----------------------------------------------------------------------------
uint8_t I2CDataReceived(void)
{
  return (rx_buffer_head_ - rx_buffer_tail_) % N_BUFFERS;
}

// -----------------------------------------------------------------------------
volatile struct I2CMessage * PopI2CMessage(void)
{
  if (rx_buffer_head_ == rx_buffer_tail_) return 0;

  volatile struct I2CMessage * result = &rx_buffer_[rx_buffer_tail_];
  rx_buffer_tail_ = (rx_buffer_tail_ + 1) % N_BUFFERS;
  return result;
}


// =============================================================================
// Public functions:

void I2CReset(void)
{
  TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN);
  i2c_error_ = I2C_ERROR_NONE;
}

// -----------------------------------------------------------------------------
// This initialization sets the I2C pin states. It should be performed prior to
// enabling interrupts.
void I2CSlaveInit(void)
{
  TWAR = 0x51;  // Base BL-Ctrl address plus general call.
  TWAMR = 0x3E;  // Respond to any of the 8 motor addresses.
  I2CAck();  // Send ACK upon receiving address match.
}


// =============================================================================
// Private functions:

// Initiate data reception and acknowledge the result.
static void I2CAck(void)
{
  TWCR = _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);
}

// -----------------------------------------------------------------------------
// I2C interrupt indicating that the I2C is active and waiting for the next
// instruction.
ISR(TWI_vect)
{
  static uint8_t length = 0;
  static volatile uint8_t * payload_ptr = &rx_buffer_[0].payload[0];
  uint8_t address;

  switch (TWSR)
  {
    case TW_SR_SLA_ACK:  // SLA+W received, ACK returned
    case TW_SR_GCALL_ACK:  // general call received, ACK returned
      address = TWDR;
      if (address != 0) address = (address - BLCTRL_BASE_ADDRESS) >> 1;
      rx_buffer_[rx_buffer_head_].address = address;
      YellowLED2On();
      break;
    case TW_SR_STOP:  // stop or repeated start condition received while selected
      rx_buffer_[rx_buffer_head_].length = length;
      rx_buffer_head_ = (rx_buffer_head_ + 1) % N_BUFFERS;
      payload_ptr = &rx_buffer_[rx_buffer_head_].payload[0];
      length = 0;
      YellowLED2Off();
      break;
    case TW_SR_DATA_ACK:  // data received, ACK returned
    case TW_SR_GCALL_DATA_ACK:  // general call data received, ACK returned
    case TW_SR_DATA_NACK:  // data received, NACK returned
    case TW_SR_GCALL_DATA_NACK:  // general call data received, NACK returned
      *payload_ptr++ = TWDR;
      ++length;
      break;
    case TW_ST_SLA_ACK:  // SLA+R received, ACK returned
      YellowLED1On();
    case TW_ST_DATA_ACK:  // data transmitted, ACK received
      TWDR = 240;  // Specific response for this module.
      break;
    case TW_ST_DATA_NACK:  // data transmitted, NACK received
      YellowLED1Off();
    case TW_ST_LAST_DATA:  // last data byte transmitted, ACK received
      break;
    case TW_BUS_ERROR:  // illegal start or stop condition
      I2CReset();
    case TW_NO_INFO:  // no state information available
      i2c_error_ = I2C_ERROR_OTHER;
      return;
      break;
  }
  I2CAck();
}
