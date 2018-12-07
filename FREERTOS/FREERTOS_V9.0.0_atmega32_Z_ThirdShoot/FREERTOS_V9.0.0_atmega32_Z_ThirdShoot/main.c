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
	
	}
}



