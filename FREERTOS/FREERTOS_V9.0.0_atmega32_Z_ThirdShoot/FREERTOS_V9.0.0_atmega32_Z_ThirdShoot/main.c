/*
 * FREERTOS_V9.0.0_atmega32_Z_ThirdShoot.c
 *
 * Created: 07/12/2018 15:32:09
 * Author : Mahmoud
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "FREERTOS.h"
#include "task.h"
#include "queue.h"

//test-1 

void TASK_F(void * pv);

void main(void)
{
	DDRA=0xff;		DDRB=0xff;		DDRC=0xff;		DDRD=0xff;
	xTaskCreate(TASK_F,NULL,configMINIMAL_STACK_SIZE,(void *)&data_arr[0],2,NULL);
	
	vTaskStartScheduler();
	
}
void TASK_F(void * pv)
{
	
	while(1)
	{
		PORTC ^=(1<<1);
		
		taskYIELD();
		//vTaskDelay(100/portTICK_RATE_MS);
	}
}



