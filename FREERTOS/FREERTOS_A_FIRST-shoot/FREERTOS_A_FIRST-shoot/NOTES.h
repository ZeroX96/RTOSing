/*
 * A_FIRST_SHOOT_NOTES.h
 *
 * Created: 01/12/2018 00:20:41
 *  Author: Mahmoud
 */ 


#ifndef NOTES_H_
#define NOTES_H_
//NOTES_
/*
1-Tasks are implemented as C functions. The only thing special about them is their prototype, which
		must return void and take a void pointer parameter.
##	void ATaskFunction( void *pvParameters );

2-A single task function definition can be used to create any number of tasks – each created task being
		a separate execution instance with its own stack and its own copy of any automatic (stack) variables
		defined within the task itself.
##  void ATaskFunction( void *pvParameters )
		{
			int iVariableExample = 0;
			// A task will normally be implemented as in infinite loop.
			for( ;; )
			{
				// The code to implement the task functionality will go here.
			}
			vTaskDelete( NULL );
		}

3- vTaskDelete( NULL ); //The NULL parameter passed to the vTaskDelete() function indicates that the task to be deleted is the calling (this) task.
		otherwise, the task handler needs to be deleted is sent as an argument 
4-	portBASE_TYPE xTaskCreate( pdTASK_CODE pvTaskCode,
								const signed portCHAR * const pcName,
								unsigned portSHORT usStackDepth,
								void *pvParameters,
								unsigned portBASE_TYPE uxPriority,
								xTaskHandle *pxCreatedTask
							);
	
5- Delay for a period. This time a call tovTaskDelay() is used which places the task into the Blocked state until the delay period has expired.
		The delay period is specified in 'ticks', but the constant portTICK_RATE_MS can be used to convert this to a more user friendly value
		in milliseconds. In this case a period of 250 milliseconds is being specified. 
##	vTaskDelay( 250 / portTICK_RATE_MS );

6- xTimeIncrement is specified in ‘ticks’. The constant portTICK_RATE_MS can be used to convert milliseconds into ticks.

7-  The xLastWakeTime variable needs to be initialized with the current tick
		count. Note that this is the only time the variable is written to explicitly.
		After this xLastWakeTime is updated automatically internally within
		vTaskDelayUntil(). 
##		xLastWakeTime = xTaskGetTickCount();

8- the idle task will  only run  when all the other tasks have no work to perform, so measuring the amount of processing time allocated to
		the idle task provides a clear indication of how much processing time is spare
		
9- If the application makes use of the vTaskDelete() API function then the Idle task hook must
		always  return  to  its  caller  within  a  reasonable  time  period.  This  is  because  the Idle  task  is
		responsible for cleaning up kernel resources after  a task has been deleted. If the idle task
		remains permanently in the Idle hook function then this clean up cannot occur.

10- Idle task hook functions must have the name and prototype  void vApplicationIdleHook( void );
##	void vApplicationIdleHook( void );

11-	The vTaskPrioritySet() API function can be used to change the priority of any task after the scheduler has been started.
		A task can change its own priority by passing NULL in place of a valid task handle
##	void vTaskPrioritySet( xTaskHandle pxTask, unsignedportBASE_TYPE uxNewPriority );

12- The uxTaskPriorityGet() API function can be used toquery the priority of a task.
##	unsigned portBASE_TYPE uxTaskPriorityGet( xTaskHandle pxTask );

13-	A task can use the vTaskDelete() API function to delete itself or any other task. 
		it's the idle task responsibility's to free-out the memory that was allocated to any deleted task 
		It is therefore important that applications that make use of the vTaskDelete() API function do
		not completely starve the idle task of all processing time.
##	void vTaskDelete( xTaskHandle pxTaskToDelete );

*/

#endif /* A_FIRST_SHOOT_NOTES_H_ */