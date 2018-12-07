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
#include "queue.h"

//test-3 structures as task messages
/*
void TX_F(void * pv);
void RX_F(void * pv);
xQueueHandle queue_1_handle;
typedef struct  
{
	portBASE_TYPE val_a;
	portBASE_TYPE val_b;
	portBASE_TYPE val_c;
	portBASE_TYPE *ptr_name;
}xData_t;
void main(void)
{
	xData_t data_arr[2]={{2,4,6,"MSA"},{3,5,7,"MMA"}};
	DDRA=0xff;		DDRB=0xff;		DDRC=0xff;		DDRD=0xff;
	char msa=0xff;
	queue_1_handle=xQueueCreate( 3,sizeof(xData_t));
	if (queue_1_handle != NULL)
	{
	
	xTaskCreate(TX_F,NULL,configMINIMAL_STACK_SIZE,(void *)&data_arr[0],2,NULL);
	xTaskCreate(TX_F,NULL,configMINIMAL_STACK_SIZE,(void *)&data_arr[1],2,NULL);
	xTaskCreate(RX_F,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	vTaskStartScheduler();
	}
	else //couldn't create a queue
	{
		PORTA=PORTB=PORTC=PORTD=0x55;
	}
	
}
void TX_F(void * pv)
{
	
	while(1)
	{
		PORTC ^=(1<<1);
		portBASE_TYPE stat= xQueueSendToBack(queue_1_handle,pv,10);
		if (stat==pdFAIL)
		{
			PORTA=0xff;
		}
		taskYIELD();
		//vTaskDelay(100/portTICK_RATE_MS);
	}
}


void RX_F(void * pv)
{
	xData_t rx_buff;
	while(1)
	{
		PORTC ^=(1<<2);
		xQueueReceive(queue_1_handle,&rx_buff,10);
		PORTB= rx_buff.val_a;
		for(portBASE_TYPE i=1;i>0;i++);
		//for(portBASE_TYPE i=1;i>0;i++);
		PORTB= rx_buff.val_b;
		for(portBASE_TYPE i=1;i>0;i++);
		//for(portBASE_TYPE i=1;i>0;i++);
		PORTB= rx_buff.val_c;
		for(portBASE_TYPE i=1;i>0;i++);
		//for(portBASE_TYPE i=1;i>0;i++);
		//vTaskDelay(100/portTICK_RATE_MS);
	}
}
*/


//test-2 Creating and using a queue
/*
void task1(void * pv);
void task2(void * pv);
	xQueueHandle queue_1_handle;
void main(void)
{
	DDRA=0xff;		DDRB=0xff;		DDRC=0xff;		DDRD=0xff;
	char msa=0xff;
	queue_1_handle=xQueueCreate( 2,sizeof(int));
	if (queue_1_handle != NULL)
	{
		
		xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,1,NULL);
		xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,1,NULL);
		
		vTaskStartScheduler();
	}
	else //couldn't create a queue
	{
		PORTA=PORTB=PORTC=PORTD=0x55;
	}
	
}
void task1(void * pv)
{
	char loc_val=(char)pv;
	while(1)
	{
		PORTC ^=(1<<1);
		PORTA=loc_val;
		portBASE_TYPE stat= xQueueSendToBack(queue_1_handle,&loc_val,10);
		loc_val++;
		if (stat==pdFAIL)
		{
			PORTA=0xff;
		}
		vTaskDelay(100);
	}
}

void task2(void * pv)
{
	portBASE_TYPE rx_buff=0;
	while(1)
	{
		PORTC ^=(1<<2);
		xQueueReceive(queue_1_handle,&rx_buff,10);
		PORTB= rx_buff;
		vTaskDelay(100);
	}
}
*/

//test-1 testing the running of v9.0.0
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

