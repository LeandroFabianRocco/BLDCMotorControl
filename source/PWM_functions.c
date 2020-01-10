/*
 * PWM_functions.c
 *
 *  Created on: 10 ene. 2020
 *      Author: leandro
 */

#include "PWM_functions.h"

/*************************************************************************
 * Función para setear el valor de CnV de los canales del FTM
 ************************************************************************/
void set_pwm_CnV(uint32_t value, uint8_t ch)
{
	FTM_MODULE->CONTROLS[ch].CnV = value;
	FTM_SetSoftwareTrigger(FTM_MODULE, true);
}
