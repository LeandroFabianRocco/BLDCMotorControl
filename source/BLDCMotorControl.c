/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    BLDCMotorControl.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "PWM_functions.h"
#include "Delays.h"
#include "RGB_LEDS.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
    // Inicializo los delays
    SysTick_init();
    RGB_LED_init();

    /*throttle_init();

    // Testeo el máximo y mínimo
    SysTick_DelayTicks(3000U);
    set_pwm_CnV(MAX_THROTTLE, PWM_CH0);
    set_pwm_CnV(MAX_THROTTLE, PWM_CH1);
    SysTick_DelayTicks(3000U);
    set_pwm_CnV(MIN_THROTTLE, PWM_CH0);
    set_pwm_CnV(MIN_THROTTLE, PWM_CH1);
    SysTick_DelayTicks(3000U);
    set_pwm_CnV(MAX_THROTTLE, PWM_CH0);
    set_pwm_CnV(MAX_THROTTLE, PWM_CH1);
    SysTick_DelayTicks(3000U);
    set_pwm_CnV(MIN_THROTTLE, PWM_CH0);
    set_pwm_CnV(MIN_THROTTLE, PWM_CH1);*/

    //GPIO_PortClear(RED_LED_GPIO, 1u << RED_LED);
    PRINTF("Hello World\n");
    uint32_t pin_status, pin_status2;
    /* Force the counter to be placed into memory. */
    volatile static int i = MIN_THROTTLE;
    set_pwm_CnV(MIN_THROTTLE, PWM_CH0);
    set_pwm_CnV(MIN_THROTTLE, PWM_CH1);
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

    	pin_status = GPIO_PinRead(SW3_MIN_GPIO, SW3_MIN_PIN);
    	if (pin_status == 0)
    	{
    		GPIO_PortClear(GREEN_LED_GPIO, 1u << GREEN_LED);
    		GPIO_PortSet(BLUE_LED_GPIO, 1u << BLUE_LED);
    		/*set_pwm_CnV(MAX_THROTTLE, PWM_CH0);
    		set_pwm_CnV(MAX_THROTTLE, PWM_CH1);*/
    		i++;
    		set_pwm_CnV(i, PWM_CH0);
    		set_pwm_CnV(i, PWM_CH1);
    		PRINTF("%d\r\n", i);
    		SysTick_DelayTicks(50U);
    	}

    	pin_status2 = GPIO_PinRead(SW2_MAX_GPIO, SW2_MAX_PIN);
		if (pin_status2 == 0)
		{
			GPIO_PortClear(BLUE_LED_GPIO, 1u << BLUE_LED);
			GPIO_PortSet(GREEN_LED_GPIO, 1u << GREEN_LED);
			/*set_pwm_CnV(MIN_THROTTLE, PWM_CH0);
			set_pwm_CnV(MIN_THROTTLE, PWM_CH1);*/
			i--;
			set_pwm_CnV(i, PWM_CH0);
			set_pwm_CnV(i, PWM_CH1);
			PRINTF("%d\r\n", i);
			SysTick_DelayTicks(50U);
		}

    	//set_pwm_CnV(i, PWM_CH0);
        //i++ ;
        //if (i >= 196)
        	//i = 97;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        //__asm volatile ("nop");
    }
    return 0 ;
}
