#include "hal.h"
#include "stm32f10x_gpio.h"

#include "board.h"

void led_on()
{
	GPIO_SetBits(GPIO_PORT_LED_1, GPIO_PIN_LED_1);
}

void led_off()
{
	GPIO_ResetBits(GPIO_PORT_LED_1, GPIO_PIN_LED_1);
}