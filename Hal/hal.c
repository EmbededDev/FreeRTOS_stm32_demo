 
#include "./private.h"
#include "stm32f10x.h"


	
void hal_init()
{
		/* Setup STM32 system (clock, PLL and Flash configuration) */
	
	__disable_interrupt();
	
	hal_rcc_init();
	
	hal_gpio_init();
	
	hal_uart_init();
	 
	hal_nvic_init();
	
	__enable_interrupt();
}