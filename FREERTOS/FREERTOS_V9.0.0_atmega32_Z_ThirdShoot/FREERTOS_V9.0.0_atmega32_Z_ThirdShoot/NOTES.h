/*
 * NOTES.h
 *
 * Created: 03/12/2018 23:26:43
 *  Author: Mahmoud
 */ 


#ifndef NOTES_H_
#define NOTES_H_
/*
1-	the Handler Task>>
		>>A Binary Semaphore can be used to unblock a task each time a particular interrupt occurs, effectively
			synchronizing the task with the interrupt. This allows the majority of the interrupt event processing to
			be implemented within the synchronized task, with only a very fast and short portion remaining directly
			in the ISR. The interrupt processing is said to have been ‘deferred’ to a ‘handler’ task.
		>>If the interrupt processing is particularly time critical then the handler task priority can be set to ensure
			the handler task always pre-empts the other tasks in the system. It will then be the task that the ISR
			returns  to  when  the  ISR  itself  has  completed  executing.  This  has  the  effect  of  ensuring the  entire
			event processing executes contiguously in time, just as if it had all been implemented within the ISR
			itself.

2-	By calling xSemaphoreTake() the handler task effectively attempts to read from the queue with a block time,
		causing the task to enter the Blocked state if the queue is empty

3-	the xSemaphoreGiveFromISR() function to place
		a token (the semaphore) into the queue, making the queue full. This causing the handler task to exit
		the Blocked state and remove the token, leaving the queue empty once more.
		Once the handler task has completed its processing it once more attempts  to read from the queue and,
		finding the queue empty, re-enters the Blocked state to wait for the next event.

4-	Before a semaphore can actually be used it must first be created.
##	void vSemaphoreCreateBinary( xSemaphoreHandle xSemaphore );
		Note that vSemaphoreCreateBinary() is actually implemented as a macro so the
		semaphore variable should be passed in directly rather than by reference.
		
5-	xSemaphoreTake() ‘Taking’  a  semaphore  means  to  ‘obtain’  or  ‘receive’ the  semaphore.   The  semaphore  can  only  be
		taken  if  it  is  available.    
##	portBASE_TYPE xSemaphoreTake( xSemaphoreHandle xSemaphore, portTickType xTicksToWait );
		>>xSemaphoreTake() must not be used from an interruptservice routine.
		>>Setting xTicksToWait to portMAX_DELAY will cause the task to wait indefinitely
			(without a timeout) if INCLUDE_vTaskSuspend is set to 1 in FreeRTOSConfig.h.

6-	xSemaphoreGiveFromISR() is a special form of xSemaphoreGive() that is specifically for use within an ISR.
##	portBASE_TYPE xSemaphoreGiveFromISR( xSemaphoreHandle xSemaphore,
										 portBASE_TYPE *pxHigherPriorityTaskWoken
									   );





*/
#endif /* NOTES_H_ */