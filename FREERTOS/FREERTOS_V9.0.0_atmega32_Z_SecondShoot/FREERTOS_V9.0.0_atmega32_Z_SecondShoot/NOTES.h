/*
 * NOTES.h
 *
 * Created: 03/12/2018 23:26:43
 *  Author: Mahmoud
 */ 


#ifndef NOTES_H_
#define NOTES_H_
/*
1-	A queue can hold a finite number of fixed size data items. The maximum number of items a queue
		can hold is called its ‘length’. Both the length and the size of each data item are set when the queue is created.
	
2-	When a task attempts to read from a queue it can optionally specify a ‘block’ time. This is the time the
		task should be kept in the Blocked state to wait for data to be available from the queue should the
		queue already be empty. A task that is in the Blocked state waiting for data to become available from
		a queue is automatically moved to the Ready state when another task or interrupt places data into the
		queue. The task will also be automatically moved from the Blocked state to the Ready state if the
		specified block time expires before data becomes available.

3-	Queues can have multiple readers so it is possible that a single queue will have more than one task
		blocked  on  it  waiting  for  data.   When  this  is  the  case  only  one  task  will  be  unblocked  when  data
		becomes available. The task that is unblocked will always be the highest priority task that was waiting
		for data. If the blocked tasks have equal priority then it will be the task that has been waiting for data
		the longest that is unblocked.

4-	Just  as  when  reading  from  a  queue,  a  task  can  optionally  specify  a  block  time  when  writing  to  a
		queue. In this case the block time is the maximum time the task should be held in the Blocked state to
		wait for space to become available on the queue should the queue already be full.

5-	Queues  can  have  multiple  writers  so  it  is  possible  that  a  full  queue  will  have  more  than  one  task
		blocked  on  it  waiting  to  complete  a  send  operation.  When  this  is  the  case  only  one  task  will  be
		unblocked when space on the queue becomes available. The task that is unblocked will always be
		the highest priority task that was waiting for space. If the blocked tasks have equal priority then it will
		be the task that has been waiting for space the longest that is unblocked.

6-	A queue must be explicitly created before it can be used. 
		Queues are referenced using variables of type xQueueHandle. xQueueCreate() is used to create a
		queue and returns an xQueueHandle to reference the queue it creates.

7-	The RAM is used to hold both the queue data structures and the items that are contained in the queue.

8-	xQueueCreate() will return NULL if there is insufficient heap RAM available for the queue to be created.

##		xQueueHandle xQueueCreate( unsigned portBASE_TYPE uxQueueLength,	//The maximum number of items the queue can hold
								   unsigned portBASE_TYPE uxItemSize		//The size in 'bytes' of each data item that can be stored in the queue. 
								 );
		>>If NULL is returned then the queue could not be created.
		>>and if A non-NULL value being returned The returned value should be stored as the handle to the created queue.

9-	xQueueSendToBack() is used tosend data to the back (tail) of a queue, and xQueueSend() is equivalent to and exactly the same as xQueueSendToBack().
	xQueueSendToFront() is used to send data to the front (head) of a queue.	

##	portBASE_TYPE xQueueSendToFront( xQueueHandle xQueue,
 									 const void * pvItemToQueue,
									 portTickType xTicksToWait
								   );
								   
##	portBASE_TYPE xQueueSendToBack( xQueueHandle xQueue,
								     const void * pvItemToQueue,
								     portTickType xTicksToWait
								   );
		Both xQueueSendToFront() and xQueueSendToBack() will return immediately if xTicksToWait is 0 and the queue is already full.
--------Setting xTicksToWait to portMAX_DELAY will cause the task to wait indefinitely (without timing out) provided INCLUDE_vTaskSuspend is set to 1 in FreeRTOSConfig.h.
10-	Never  call  xQueueSendToFront()  or  xQueueSendToBack()  from  an  interrupt  service  routine.
		The interrupt safe versions xQueueSendToFrontFromISR()  and xQueueSendToBackFromISR() should be used in their place.

11-	>>xQueueReceive()  is  used  to  receive  (read)  an  item  from  a  queue.   The  item  that  is  received  is removed from the queue.
	>>xQueuePeek()  is  used  to  receive  an  item  from  a  queue  without  the  item  being  removed  from  the queue.
		>>>>xQueuePeek() will receive the item from the head of the queue without modifying the data that is stored in the queue, or the order in which data is stored in the queue.
	Never  call  xQueueReceive()  or  xQueuePeek() from  an  interrupt service  routine.  The  interrupt  safe xQueueReceiveFromISR()
##	portBASE_TYPE xQueueReceive(
									xQueueHandle xQueue,
									const void * pvBuffer,
									portTickType xTicksToWait
								);
##	portBASE_TYPE xQueuePeek(
									xQueueHandle xQueue,
									const void * pvBuffer,
									portTickType xTicksToWait
								);	

		If xTicksToWait is zero then both xQueueReceive() and xQueuePeek() will	return immediately if the queue is already empty.
----Setting xTicksToWait to portMAX_DELAY will cause the task to wait indefinitely (without timing out) provided INCLUDE_vTaskSuspend is set to 1 in FreeRTOSConfig.h.

12-	uxQueueMessagesWaiting() is used to query the number of items that are currently in a queue. Never  call  uxQueueMessagesWaiting()  from  an  interrupt  service  routine.
		The  interrupt  safe uxQueueMessagesWaitingFromISR() should be used in its place.
##	unsigned portBASE_TYPE uxQueueMessagesWaiting( xQueueHandle xQueue );

13-	Allow the other sender task to execute. taskYIELD() informs the scheduler that a switch to another task should occur now rather than
		keeping this task in the Running state until the end of the current time slice. 
##	taskYIELD();

14-	





*/
#endif /* NOTES_H_ */