#ifndef UART_H_
#define UART_H_

#include "values.h"

#define		PCLK	50000000U
#define		BAUD	57600U

void init_uart(uint32 baud_rate);
void putc(uint32 bit);
uint32 getc(void);

#endif