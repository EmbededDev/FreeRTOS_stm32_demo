#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_gpio.h"

#include <stdio.h> 
 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define RECV_BUFF_SIZE 100

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char recv_buff[RECV_BUFF_SIZE];
int recv_index;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

 


int fputc(int c, FILE *stream)
{
	while(!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
	
	USART_SendData(USART1, c);
//	while(!USART_GetFlagStatus(USART1, USART_FLAG_TC));
 
    return c;
} 
  
void hal_uart_init()
{
	USART_InitTypeDef USART_InitStruct;
	USART_ClockInitTypeDef USART_ClockInitStruct;
		
	USART_StructInit(&USART_InitStruct);
	
	USART_DeInit(USART1);
	USART_InitStruct.USART_BaudRate = 115200;
	USART_Init(USART1, &USART_InitStruct); 
	 
	USART_ClockStructInit(&USART_ClockInitStruct);
	//USART_ClockInit(USART1, &USART_ClockInitStruct);

	USART_ClearFlag(USART1, USART_FLAG_TC);
	USART_ClearFlag(USART1, USART_FLAG_RXNE);
	USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable rx interrupt
	
	USART_Cmd(USART1, ENABLE);
}


void hal_uart1_rx_it_irq()
{
	char rc = 0;
	if(USART_GetITStatus(USART1, USART_IT_RXNE)) {  
		rc = USART_ReceiveData(USART1);
		recv_buff[recv_index++ % RECV_BUFF_SIZE] = rc;
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
}
