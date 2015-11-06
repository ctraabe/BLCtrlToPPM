// Information:
//
// UART stands for Universal Asynchronous Receiver/Transmitter. A UART uses 2
// wires for data transmission: one for transmitting, and one for receiving.
// Data transfers may be started at any time, but must occur at a pre-agreed
// rate, called the BAUD rate. Transmit and receive can occur simultaneously
// (i.e. one does not impact the other). When no data is being transferred, the
// output is set to the high state (1). A single low bit (0) marks the start of
// a new data packet. This UART is set to the following:
//
//   - 57600 BAUD (57.6 kbits / second)
//   - 8 bits of data follow the single start bit
//   - data packets are closed with a single high bit and without a parity bit
//
// Additionally, this file sets up a buffering scheme for minimal-impact,
// interrupt-based serial transmission and reception.
//
// Incoming bytes are immediately placed into a small ring buffer (rx_buffer_)
// by the Rx interrupt handler. The function ProcessIncomingUART() passes bytes
// from the ring buffer to the appropriate Rx handler. A larger shared data
// buffer (data_buffer_) is provided for temporary storage for the Rx handlers.
// The data in the shared data buffer must be processed immediately after the
// final byte in a message is read form the ring buffer so that the data buffer
// may be used in handling the next message.
//
// The function SendPendingUART() invokes functions that handle data Tx
// requests. A shared Tx buffer (tx_buffer_) is provided for interrupt-based
// transmission. The Tx buffer must be requested via the function
// RequestTxBuffer(), since the Tx buffer should not modified during an ongoing
// transmission. If access to the buffer is granted, the outgoing message should
// be written to the Tx buffer. The function UARTTxBuffer() initiates the
// interrupt-driven transmission of the buffer.
//
// Two other BLOCKING functions are provided to immediately send a single byte
// (UARTTxByte) and to mimic the standard printf function (UARTPrintf). These
// functions are BLOCKING, meaning that non-interrupt computation is blocked
// until transmission is complete. Therefore, these functions should not be
// called when the motors are running.

#include "uart.h"

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "arduino.h"


// =============================================================================
// Private data:

#define USART0_BAUD (57600)

static volatile uint8_t rx_buffer_head_ = 0, rx_buffer_[RX_BUFFER_LENGTH];
static volatile uint8_t tx_bytes_remaining_ = 0, *tx_ptr_ = 0;
// static uint8_t data_buffer_[DATA_BUFFER_LENGTH];
static uint8_t tx_buffer_[TX_BUFFER_LENGTH];
static uint8_t tx_overflow_counter_ = 0;


// =============================================================================
// Public functions:

void UARTInit(void)
{
  // Pull up Rx pin.
  PinMode(0, INPUT_PULLUP);
  // Set the baud rate.
  UBRR0 = F_CPU / 8 / USART0_BAUD - 1;
  // Set UART Double Speed (U2X).
  UCSR0A = (1 << U2X0);
  // Enable USART0 receiver and transmitter and interrupts.
  UCSR0B = (1 << RXCIE0)  // RX Complete Interrupt Enable
         | (0 << TXCIE0)  // TX Complete Interrupt Enable
         | (0 << UDRIE0)  // Data Register Empty Interrupt Enable
         | (1 << TXEN0)  // Transmitter Enable
         | (1 << RXEN0)  // Receiver Enable
         | (0 << UCSZ02);  // 9-bit Character Size Enable
  UCSR0C = (0 << UMSEL01) | (0 << UMSEL00)  // USART Mode (asynchronous)
         | (0 << UPM01) | (0 << UPM00)  // Parity Bit Mode (none)
         | (0 << USBS0)  // 2 Stop Bit Enable
         | (1 << UCSZ01) | (1 << UCSZ00);  // Character Size (8-bits)
}

// -----------------------------------------------------------------------------
// This function processes bytes that have been read into the Rx ring buffer
// (rx_buffer_) by the Rx interrupt handler. Each byte is passed to the
// appropriate Rx handler, which may place it into the temporary data buffer
// (data_buffer_).
void ProcessIncomingUART(void)
{
  static uint8_t rx_buffer_tail = 0;
  // static enum UARTRxMode mode = UART_RX_MODE_IDLE;

  while (rx_buffer_tail != rx_buffer_head_)
  {
    // Move the ring buffer tail forward.
    rx_buffer_tail = (rx_buffer_tail + 1) % RX_BUFFER_LENGTH;

    // Do something with the received data
  }
}

// -----------------------------------------------------------------------------
// This function returns the address of the shared Tx buffer (tx_buffer_) if it
// is available of zero if not.
uint8_t * RequestUARTTxBuffer(void)
{
  if (tx_bytes_remaining_)
  {
    tx_overflow_counter_++;
    return 0;
  }
  return tx_buffer_;
}

// -----------------------------------------------------------------------------
// This function calls handlers for pending data transmission requests.
void SendPendingUART(void)
{
}

// -----------------------------------------------------------------------------
// This function initiates the transmission of the data in the Tx buffer.
void UARTTxBuffer(uint8_t tx_length)
{
  if (tx_length == 0) return;
  tx_ptr_ = &tx_buffer_[0];
  tx_bytes_remaining_ = tx_length;
  UCSR0B |= _BV(UDRIE0);  // Enable the USART0 data register empty interrupt.
}

// -----------------------------------------------------------------------------
// This function immediately transmits a byte and blocks computation until
// transmission is commenced.
void UARTTxByte(uint8_t byte)
{
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = byte;
}

// -----------------------------------------------------------------------------
// This function mimics printf, but puts the result on the UART stream. It also
// adds the end-of-line characters and checks that the character buffer is not
// exceeded. Note that this function is slow and blocking.
void UARTPrintf_P(const char *format, ...)
{
  char ascii[103];  // 100 chars + 2 newline chars + null terminator

  va_list arglist;
  va_start(arglist, format);
  int length = vsnprintf_P(ascii, 101, format, arglist);
  va_end(arglist);

  if (length < 101)
    sprintf_P(&ascii[length], PSTR("\n\r"));
  else
    sprintf_P(&ascii[80], PSTR("... MESSAGE TOO LONG\n\r"));

  char *pointer = &ascii[0];
  while (*pointer) UARTTxByte(*pointer++);
}


// =============================================================================
// Private functions:

// This function is called upon the "USART0 data register empty" interrupt,
// indicating that the transmitter is ready to load another byte.
ISR(USART0_UDRE_vect)
{
  if (tx_bytes_remaining_)
  {
    UDR0 = *(tx_ptr_++);
    tx_bytes_remaining_--;
  }
  else
  {
    UCSR0B &= ~_BV(UDRIE0);  // Disable this interrupt
  }
}

// -----------------------------------------------------------------------------
ISR(USART0_RX_vect)
{
  rx_buffer_head_ = (rx_buffer_head_ + 1) % RX_BUFFER_LENGTH;
  rx_buffer_[rx_buffer_head_] = UDR0;
}
