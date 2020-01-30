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

// ---------------------------------------------------------------------------+
// -- SS_Init
// ---------------------------------------------------------------------------+
void SS_Init()
{

}

// ---------------------------------------------------------------------------+
// -- SS_Commutate GPIO
// ---------------------------------------------------------------------------+
void SS_Commutate_Type1(uint8_t state)
{
	uint8_t commutation_table[8][6] =
	{
			{	0,	0,	0,	0,	0,	0	},
			{	1,	0,	0,	1,	0,	0	},
			{	1,	0,	0,	0,	0,	1	},
			{	0,	0,	1,	0,	0,	1	},
			{	0,	1,	1,	0,	0,	0	},
			{	0,	1,	0,	0,	1,	0	},
			{	0,	0,	0,	1,	1,	0	},
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
// -- SS_Commutate
// ---------------------------------------------------------------------------+
void SS_Commutate_type2(uint8_t state)
{
	uint32_t pwm = 2500;
	uint32_t max = 6500;

	uint8_t commutation_table[8][6] =
	{
			{	pwm,	0,		0,		max,	0,		0	},
			{	pwm,	0,		0,		0,		0,		max	},
			{	0,		0,		pwm,	0,		0,		max	},
			{	0,		max,	pwm,	0,		0,		0	},
			{	0,		max,	0,		0,		pwm,	0	},
			{	0,		0,		0,		max,	pwm,	0	},
	};
}

// ---------------------------------------------------------------------------+
// -- SS_Commutate -> Driver tests
// ---------------------------------------------------------------------------+
void SS_Commutate_Type3(uint8_t state)
{

	uint8_t commutation_table[][6] =
	{
			{	0,	1,	0,	1,	0,	1	},
			{	1,	0,	1,	0,	1,	0	},
	};

	uint16_t gpio_pins[] = {
			S1_H_Pin, S1_L_Pin, S2_H_Pin, S2_L_Pin, S3_H_Pin, S3_L_Pin
	};

	GPIO_TypeDef *gpio_ports[] = {
			S1_H_GPIO_Port, S1_L_GPIO_Port, S2_H_GPIO_Port, S2_L_GPIO_Port, S3_H_GPIO_Port, S3_L_GPIO_Port
	};

	uint8_t sel = state % 2;

	for(uint8_t n=0; n<6; n++)
	{
		HAL_GPIO_WritePin(gpio_ports[n], gpio_pins[n], commutation_table[sel][n]);
	}
}


// ---------------------------------------------------------------------------+
// -- SS_Commutate -> Driver tests
// ---------------------------------------------------------------------------+
void SS_Commutate_Type4(uint8_t state)
{

	uint8_t commutation_table[][6] =
	{
			{	0,	0,	0,	0,	0,	0	},	// 0
			{	1,	0,	0,	1,	0,	0	},	// 1
			{	0,	0,	1,	0,	0,	1	},	// 2
			{	0,	1,	0,	0,	1,	0	},	// 3
			{	1,	0,	0,	0,	0,	1	},	// 4
			{	0,	1,	1,	0,	0,	0	},	// 5
			{	0,	0,	0,	1,	1,	0	},	// 6
			{	0,	0,	0,	0,	0,	0	},	// 7
	};

	uint16_t gpio_pins[] = {
			S1_H_Pin, S1_L_Pin, S2_H_Pin, S2_L_Pin, S3_H_Pin, S3_L_Pin
	};

	GPIO_TypeDef *gpio_ports[] = {
			S1_H_GPIO_Port, S1_L_GPIO_Port, S2_H_GPIO_Port, S2_L_GPIO_Port, S3_H_GPIO_Port, S3_L_GPIO_Port
	};

//	uint8_t sel = state % 2;

	for(uint8_t n=0; n<6; n++)
	{
		HAL_GPIO_WritePin(gpio_ports[n], gpio_pins[n], commutation_table[state][n]);
	}
}


// ---------------------------------------------------------------------------+
// -- SS_Commutate -> Driver tests
// ---------------------------------------------------------------------------+
void SS_Commutate_Type5(uint8_t state)
{

	uint8_t commutation_table[][6] =
	{
			{	0,	0,	1,	0,	0,	1	},	// 0
			{	0,	0,	1,	0,	0,	1	},	// 1
			{	0,	0,	1,	0,	0,	1	},	// 2
			{	0,	0,	1,	0,	0,	1	},	// 3
			{	0,	0,	1,	0,	0,	1	},	// 4
			{	0,	0,	1,	0,	0,	1	},	// 5
			{	0,	0,	1,	0,	0,	1	},	// 6
			{	0,	0,	1,	0,	0,	1	},	// 7
	};

	uint16_t gpio_pins[] = {
			S1_H_Pin, S1_L_Pin, S2_H_Pin, S2_L_Pin, S3_H_Pin, S3_L_Pin
	};

	GPIO_TypeDef *gpio_ports[] = {
			S1_H_GPIO_Port, S1_L_GPIO_Port, S2_H_GPIO_Port, S2_L_GPIO_Port, S3_H_GPIO_Port, S3_L_GPIO_Port
	};

	uint8_t sel = 1;

	for(uint8_t n=0; n<6; n++)
	{
		HAL_GPIO_WritePin(gpio_ports[n], gpio_pins[n], commutation_table[sel][n]);
	}
}

// ---------------------------------------------------------------------------+
// -- SS_Commutate GPIO
// ---------------------------------------------------------------------------+
void SS_Commutate_Type6(uint8_t state)
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

////	HAL_GPIO_WritePin(S1_H_GPIO_Port, S1_H_Pin, GPIO_PIN_RESET);
////	HAL_GPIO_WritePin(S1_L_GPIO_Port, S1_L_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(S2_H_GPIO_Port, S2_H_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(S2_L_GPIO_Port, S2_L_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(S3_H_GPIO_Port, S3_H_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(S3_L_GPIO_Port, S3_L_Pin, GPIO_PIN_RESET);
//
//	HAL_GPIO_WritePin(S1_H_GPIO_Port, S1_H_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(S1_L_GPIO_Port, S1_L_Pin, GPIO_PIN_SET);

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
