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
void SS_Commutate_Type1(uint8_t state);
void SS_Commutate_Type3(uint8_t state);
void SS_Commutate_Type4(uint8_t state);
void SS_Commutate_Type5(uint8_t state);
void SS_Commutate_Type6(uint8_t state);




#endif /* INC_SIX_STEP_H_ */
