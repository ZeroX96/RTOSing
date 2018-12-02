/*
 * FREERTOS_A_FIRST-shoot.c
 *
 * Created: 11/08/2018 13:20:03
 * Author : Mahmoud
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
//test_4  >>  Deleting a Task By itself
/*
void taskA(void * pv)
{
	portBASE_TYPE cntr=0;
	while(1)
	{
		PORTC ^= (1<<0);
		PORTA=uxTaskPriorityGet(NULL);
		for (uint16_t a=1;a>0;a++);
		for (uint16_t a=1;a>0;a++);
			cntr++;
		if (cntr == 5)
		{
			vTaskDelete(NULL);
		}
	}
}
int main(void)
{

	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
	portBASE_TYPE *xhandleTaskA=NULL;
	portBASE_TYPE *xhandleTaskB=NULL;
	xTaskCreate(taskA,NULL,configMINIMAL_STACK_SIZE,(void*)xhandleTaskB,2,(void*)xhandleTaskA);//&A it would be better if a structure and you r the user and know hot it'll be used
	vTaskStartScheduler();
}
*/

//test_3  >>  switching bet. tasks by just changing the priority
/*
void taskA(void * pv)
{
	
	while(1)
	{
		PORTC ^= (1<<0);
		PORTA=uxTaskPriorityGet(NULL);
		for (uint16_t a=1;a>0;a++);
		for (uint16_t a=1;a>0;a++);
		vTaskPrioritySet(NULL,1);
		PORTA=uxTaskPriorityGet(NULL);
		//for (uint16_t a=1;a>0;a++);
		vTaskPrioritySet((portBASE_TYPE*)pv,3);
		//vTaskDelay(10/portTICK_RATE_MS);
	}
}
void taskB(void * pv)
{
	
	while(1)
	{
		PORTC ^= (1<<1);
		PORTB=uxTaskPriorityGet(NULL);
		for (uint16_t a=1;a>0;a++);
		for (uint16_t a=1;a>0;a++);
		vTaskPrioritySet(NULL,1);
		PORTB=uxTaskPriorityGet(NULL);
		//for (uint16_t a=1;a>0;a++);
		vTaskPrioritySet((portBASE_TYPE*)pv,3);
		//uxTaskPriorityGet(NULL);
		//vTaskDelay(10/portTICK_RATE_MS);
	}
}
int main(void)
{

	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
	portBASE_TYPE *xhandleTaskA=NULL;
	portBASE_TYPE *xhandleTaskB=NULL;
	xTaskCreate(taskA,NULL,configMINIMAL_STACK_SIZE,(void*)xhandleTaskB,2,(void*)xhandleTaskA);//&A it would be better if a structure and you r the user and know hot it'll be used
	xTaskCreate(taskB,NULL,configMINIMAL_STACK_SIZE,(void*)xhandleTaskA,2,(void*)xhandleTaskB);//&A it would be better if a structure and you r the user and know hot it'll be used
	vTaskStartScheduler();
}
*/

//test_2  >>  task_Delay() and task_Delay_Until()
/*
void task0(void * pv)
{
	//portTickType xLASTWAKETIME=0;
	//xLASTWAKETIME=xTaskGetTickCount();
	while(1)
	{
		PORTC ^= (1<<0);
		PORTA=(*(char *)pv)++;
		//vprintf("msa");
		for (uint16_t a=1;a>0;a++);
		//(*(char*)(pv))++;
		//vTaskDelayUntil(&xLASTWAKETIME,(250/portTICK_RATE_MS));
		//		vTaskDelay(33/portTICK_RATE_MS);
	}
}

void task1(void * pv)
{
	portTickType xLASTWAKETIME=0;
	xLASTWAKETIME=xTaskGetTickCount();
	while(1)
	{
		PORTC ^= (1<<1);
		PORTB=(*(char *)pv)++;		
		//(*(char*)(pv))++;
		vTaskDelayUntil(&xLASTWAKETIME,(10/portTICK_RATE_MS));
		vTaskDelay(10/portTICK_RATE_MS);
	}
}

void task2(void * pv)
{
	portTickType xLASTWAKETIME=0;
	xLASTWAKETIME=xTaskGetTickCount();
	while(1)
	{
		PORTC ^= (1<<2);
		//vprintf("msa");
		PORTD=(*(char *)pv)++;
		for (uint16_t a=1;a>0;a++);
		(*(char*)(pv))++;
		vTaskDelayUntil(&xLASTWAKETIME,(250/portTICK_RATE_MS));
		vTaskDelay(33/portTICK_RATE_MS);
	}
}


int main(void)
{

	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRD=0xff;
	char msa=0xff;
	xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,0,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
 	xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,1,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
 	xTaskCreate(task0,NULL,configMINIMAL_STACK_SIZE,(void *)&msa,1,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
		vTaskStartScheduler();
}
*/

//test_1  >>  creating many tasks,as normal or after running the os i.e dynamically  >>  testing the task parameters
/*
void task1(void * pv)
{
	while(1)
	{
		for (uint16_t a=1;a>0;a++);
		PORTC ^= (1<<1);
		PORTA=*((char *)pv);
		vTaskDelay(5);
	}
}
void task2(void * pv)
{
	while(1)
	{
		for (uint16_t a=1;a>0;a++);
		PORTC ^= (1<<2);
		PORTB=*((char *)pv);
		vTaskDelay(10);
	}
}
void task3(void * pv)
{
	while(1)
	{
		for (uint16_t a=1;a>0;a++);
		PORTC ^= (1<<3);
		(*(char *)pv)++;
		vTaskDelay(15);
	}
}
void task4(void * pv)
{
	while(1)
	{
		for (uint16_t a=1;a>0;a++);
		PORTD ^= (1<<3);
		(*(char *)pv)--;
		vTaskDelay(20);
	}
}

void task5(void * pv)
{
	while(1)
	{
			xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,pv,1,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
			xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,pv,2,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
			xTaskCreate(task3,NULL,configMINIMAL_STACK_SIZE,pv,3,NULL);//&A it would be better if a structure and you r the user and know hot it'll be used
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