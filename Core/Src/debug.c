/*
 * debug.c
 *
 *  Created on: Jan 17, 2020
 *      Author: ashri
 */


// ---------------------------------------------------------------------------+
// -- Includes
// ---------------------------------------------------------------------------+

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#include "main.h"
#include "usart.h"

#include "debug.h"



// ---------------------------------------------------------------------------+
// -- debug_printf
// -- used to print data over UART2 (same as connected to st-link USB)
// -- usage: similar to printf
// -- source: https://embeddedgurus.com/stack-overflow/2009/02/effective-c-tips-1-using-vsprintf/
// ---------------------------------------------------------------------------+

void debug_printf(const char* format, ... )
{
	uint8_t str_print[1024];
	va_list args;

	va_start(args, format);

	size_t len = vsnprintf((char*)str_print, sizeof(str_print), format, args);
	HAL_UART_Transmit(&huart2, str_print, len, HAL_MAX_DELAY);

	va_end(args);
}
