#include <intrinsics.h>
#include "stm32f10x.h"

#include <stdio.h> 


#include "hal.h"
#include "bsp.h"
// rtos
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void LedTest(void);
void wait(void); 
void TaskLed(void *param);
void TaskLog(void *param);
/* Private functions ---------------------------------------------------------*/




/*************************************************************************
* Function Name: main
* Parameters: none
*
* Return: none
*
* Description: main
*
*************************************************************************/
void main(void)
{
	
	hal_init();
	
	xTaskCreate(TaskLed, "TaskLed", 100, NULL, 4, NULL);
	xTaskCreate(TaskLog, "TaskLog", 100, NULL, 5, NULL);
	
	
	/* Start the scheduler. */
	vTaskStartScheduler();
 
	return;
	
	
}

//void wait(void)
//{
//	long i = 0;
//	
//	for(i=0; i<1000000; i++)
//		;
//}


void TaskLed(void *param)
{
	while(1)
	{
		led_off();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		
		led_on();
		vTaskDelay(1000 / portTICK_PERIOD_MS);		
	}
}

void TaskLog(void *param)
{
	
	while(1) {
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		printf("hello\r\n");
	}
}