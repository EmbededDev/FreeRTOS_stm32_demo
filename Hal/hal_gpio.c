#include "stm32f10x.h" 
#include "stm32f10x_gpio.h"
 
#include "board.h"
 
void hal_uart_io_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_StructInit(&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void hal_gpio_map()
{
	//GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);  // PA9,PA10 不需要复用
}
 
void hal_led_io_init()
{ 
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_StructInit(&GPIO_InitStruct);
 
	GPIO_InitStruct.GPIO_Pin = GPIO_PIN_LED_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIO_PORT_LED_1, &GPIO_InitStruct); 
}

void hal_gpio_init()
{
	GPIO_DeInit(GPIOA);
	GPIO_AFIODeInit();
	
	hal_uart_io_init();
	hal_gpio_map();
	hal_led_io_init();
}
