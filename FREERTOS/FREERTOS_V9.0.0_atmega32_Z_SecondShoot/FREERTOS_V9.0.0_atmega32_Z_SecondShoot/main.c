/*
 * FREERTOS_V9.0.0_atmega32_Z_SecondShoot.c
 *
 * Created: 03/12/2018 21:59:08
 * Author : Mahmoud
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "FREERTOS.h"
#include "task.h"

void task1(void * pv)
{
	while(1)
	{
				
	}
}

int main(void)
{
	
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
	char msa=0xff;
	xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,5,NULL);
	vTaskStartScheduler();
}


//testing the running of v9.0.0
/*
void task4(void * pv)
{
	while(1)
	{
		//for (uint16_t a=1;a>0;a++);
		PORTD ^= (1<<3);
		(*(char *)pv)--;
		vTaskDelay(20);
	}
}

void task5(void * pv)
{
	while(1)
	{
// 		xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,pv,1,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
// 		xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,pv,2,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
// 		xTaskCreate(task3,NULL,configMINIMAL_STACK_SIZE,pv,3,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
		xTaskCreate(task4,NULL,configMINIMAL_STACK_SIZE,pv,4,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
		vTaskDelete(NULL);
		PORTD=0xff;
	}
}

int main(void)
{
	
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
	char msa=0xff;

	xTaskCreate(task5,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,5,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
	vTaskStartScheduler();
}
*/

