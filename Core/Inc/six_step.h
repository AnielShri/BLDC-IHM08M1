/*
 * six_step.h
 *
 *  Created on: Jan 27, 2020
 *      Author: ashri
 */

#ifndef INC_SIX_STEP_H_
#define INC_SIX_STEP_H_

// ---------------------------------------------------------------------------+
// -- constants
// ---------------------------------------------------------------------------+


// ---------------------------------------------------------------------------+
// -- public functions
// ---------------------------------------------------------------------------+
void SS_Init();
void SS_Set_Duty_Ratio(uint32_t new_duty);
void SS_Commutate_Type1(uint8_t state);
void SS_Commutate_Type2(uint8_t state);


#endif /* INC_SIX_STEP_H_ */
