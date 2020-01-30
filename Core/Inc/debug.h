/*
 * debug.h
 *
 *  Created on: Jan 17, 2020
 *      Author: ashri
 */

#ifndef INC_DEBUG_H_
#define INC_DEBUG_H_

#include <string.h>

#define WELCOME_MSG "\r\n----\r\nBuild: "  __DATE__  " @ "   __TIME__   "\r\n----\r\n"

void debug_printf(const char* format, ... );

#endif /* INC_DEBUG_H_ */
