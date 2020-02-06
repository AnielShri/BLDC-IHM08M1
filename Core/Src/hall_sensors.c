/*
 * hall_sensors.c
 *
 *  Created on: Feb 4, 2020
 *      Author: ashri
 */


// ---------------------------------------------------------------------------+
// -- includes
// ---------------------------------------------------------------------------+
#include "main.h"
#include "hall_sensors.h"
#include "gpio.h"

// ---------------------------------------------------------------------------+
// -- private variables
// ---------------------------------------------------------------------------+
uint8_t _hs_state;

// ---------------------------------------------------------------------------+
// -- init
// ---------------------------------------------------------------------------+
void HS_Init()
{
	_hs_state = HS_Calculate_State();
}

// ---------------------------------------------------------------------------+
// -- calc state
// ---------------------------------------------------------------------------+
uint8_t HS_Calculate_State()
{

	uint8_t commutation_state[] = {
		//State	| HALL_321
		//=================
		 0, //	| 0
		 6, //	| 1
		 4, //	| 2
		 5, //	| 3
		 2, //	| 4
		 1, //	| 5
		 3, //	| 6
		 7, //	| 7
	};

	// read current HALL values
	uint8_t val_H1 = HAL_GPIO_ReadPin(H1_GPIO_Port, H1_Pin);
	uint8_t val_H2 = HAL_GPIO_ReadPin(H2_GPIO_Port, H2_Pin);
	uint8_t val_H3 = HAL_GPIO_ReadPin(H3_GPIO_Port, H3_Pin);

	// compound values
	uint8_t total_val = (val_H3 << 2) | (val_H2 << 1) | (val_H1  << 0);

	// sanity check
	// TODO add some kind of emergency stop here?
	if(total_val < 1 || total_val > 6)
	{
		return 0; // this should not be happening
	}

	_hs_state = commutation_state[total_val];

	return _hs_state;
}
