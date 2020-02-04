/*
 * six_step.c
 *
 *  Created on: Jan 27, 2020
 *      Author: ashri
 */


// ---------------------------------------------------------------------------+
// -- includes
// ---------------------------------------------------------------------------+

#include "main.h"
#include "six_step.h"
#include "tim.h"

// ---------------------------------------------------------------------------+
// -- private variables
// ---------------------------------------------------------------------------+
uint32_t _pwm_value;

// ---------------------------------------------------------------------------+
// -- SS_Init
// ---------------------------------------------------------------------------+
void SS_Init()
{
	_pwm_value = 0;
	SS_Commutate_Type2(0); // disable all switches
}

// ---------------------------------------------------------------------------+
// -- SS_Set_Duty_Ratio
// ---------------------------------------------------------------------------+
void SS_Set_Duty_Ratio(uint32_t new_duty)
{
	if(new_duty < TIM1->ARR)
	{
		_pwm_value = new_duty;
	}
	else
	{
		_pwm_value = TIM1->ARR;
	}

}

// ---------------------------------------------------------------------------+
// -- SS_Commutate GPIOs
// ---------------------------------------------------------------------------+
void SS_Commutate_Type1(uint8_t state)
{
	uint8_t commutation_table[8][6] =
	{
			{	0,	0,	0,	0,	0,	0	},
			{	1,	1,	0,	0,	1,	0	},
			{	1,	1,	1,	0,	0,	0	},
			{	1,	0,	1,	1,	0,	0	},
			{	0,	0,	1,	1,	1,	0	},
			{	0,	0,	1,	0,	1,	1	},
			{	1,	0,	0,	0,	1,	1	},
			{	0,	0,	0,	0,	0,	0	},
	};

	uint16_t gpio_pins[] = {
			S1_H_Pin, S1_L_Pin, S2_H_Pin, S2_L_Pin, S3_H_Pin, S3_L_Pin
	};

	GPIO_TypeDef *gpio_ports[] = {
			S1_H_GPIO_Port, S1_L_GPIO_Port, S2_H_GPIO_Port, S2_L_GPIO_Port, S3_H_GPIO_Port, S3_L_GPIO_Port
	};

	for(uint8_t n=0; n<6; n++)
	{
		HAL_GPIO_WritePin(gpio_ports[n], gpio_pins[n], commutation_table[state][n]);
	}
}

// ---------------------------------------------------------------------------+
// -- SS_Commutate PWM
// ---------------------------------------------------------------------------+
void SS_Commutate_Type2(uint8_t state)
{

	GPIO_PinState low = GPIO_PIN_RESET;
	GPIO_PinState high = GPIO_PIN_SET;
	uint32_t pwm = _pwm_value;

	uint32_t commutation_table[8][6] =
	{
			{	0,		low,	0,		high,	0,		high	},
			{	pwm,	high,	0,		low,	0,		high	},
			{	pwm,	high,	0,		high,	0,		low		},
			{	0,		high,	pwm,	high,	0,		low		},
			{	0,		high,	pwm,	high,	0,		high	},
			{	0,		low,	0,		high,	pwm,	high	},
			{	0,		high,	0,		low,	pwm,	high	},
			{	0,		high,	0,		high,	0,		high	},
	};

	uint16_t gpio_pins[] = {
			S1_L_Pin, S2_L_Pin, S3_L_Pin,
	};

	GPIO_TypeDef *gpio_ports[] = {
			S1_L_GPIO_Port, S2_L_GPIO_Port, S3_L_GPIO_Port,
	};

	uint32_t tim_channels[] = {
			TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3,
	};

	// toggle low switches first
	for(uint8_t n = 0; n < 3; n++)
	{
		HAL_GPIO_WritePin(gpio_ports[n], gpio_pins[n], commutation_table[state][n*2+1]);
	}

	// adjust PWM
	for(uint8_t n = 0; n < 3; n++)
	{
		__HAL_TIM_SET_COMPARE(&htim1, tim_channels[n], commutation_table[state][n*2]);
	}

}

// ---------------------------------------------------------------------------+
// -- SS_Commutate PWM
// ---------------------------------------------------------------------------+
void SS_Commutate_Type3(uint8_t state)
{

/*
	Truth table L6398
	Input			  Output
	 HIN	| LIN	| HVG	| LVG	|
	=================================
	 L 		| H		| L		| L		|
	 H		| L		| L		| L		|
	 L		| L		| L		| H		|
	 H		| H		| H 	| L		|
*/

	GPIO_PinState on = GPIO_PIN_RESET;
	GPIO_PinState off = GPIO_PIN_SET;
	uint32_t pwm = 0;

	uint32_t commutation_table[8][6] =
	{
		{	0,		off,	0,		off,	0,		off	},	// 0
		{	pwm,	off,	0,		on,		0,		off	},	// 1
		{	pwm,	off,	0,		off,	0,		on	},	// 2
		{	0,		off,	pwm,	off,	0,		on	},	// 3
		{	0,		on,		pwm,	off,	0,		off	},	// 4
		{	0,		on,		0,		off,	pwm,	off	},	// 5
		{	0,		off,	0,		on,		pwm,	off	},	// 6
		{	0,		off,	0,		off,	0,		off	},	// 7
	};

	uint16_t gpio_pins[] = {
			S1_L_Pin, S2_L_Pin, S3_L_Pin,
	};

	GPIO_TypeDef *gpio_ports[] = {
			S1_L_GPIO_Port, S2_L_GPIO_Port, S3_L_GPIO_Port,
	};

	uint32_t tim_channels[] = {
			TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3,
	};

	// turn off all high-side switches first
	for(uint8_t n = 0; n < 3; n++)
	{
		__HAL_TIM_SET_COMPARE(&htim1, tim_channels[n], 0);
	}

	// toggle low-side switches
	for(uint8_t n = 0; n < 3; n++)
	{
		HAL_GPIO_WritePin(gpio_ports[n], gpio_pins[n], commutation_table[state][n*2+1]);
	}

	// adjust PWM
	for(uint8_t n = 0; n < 3; n++)
	{
		__HAL_TIM_SET_COMPARE(&htim1, tim_channels[n], commutation_table[state][n*2]);
	}
}
