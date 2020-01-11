/*
 * RGB_LEDS.c
 *
 *  Created on: 14 abr. 2019
 *      Author: leandro
 */

#include "RGB_LEDS.h"


void RGB_LED_init(void)
{
	// Define the init structure for the output LEDs pins
	gpio_pin_config_t led_config = {
		kGPIO_DigitalOutput, 1,
	};
	// Inicialización de los LEDs en alto
	GPIO_PinInit(RED_LED_GPIO, RED_LED, &led_config);
	GPIO_PinInit(GREEN_LED_GPIO, GREEN_LED, &led_config);
	GPIO_PinInit(BLUE_LED_GPIO, BLUE_LED, &led_config);
	GPIO_PortSet(BLUE_LED_GPIO, 1u << BLUE_LED);
	GPIO_PortSet(RED_LED_GPIO, 1u << RED_LED);
	GPIO_PortSet(GREEN_LED_GPIO, 1u << GREEN_LED);
}


