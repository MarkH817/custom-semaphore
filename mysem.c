/*
 * mysem.c
 *
 *  Created on: Nov 12, 2017
 *      Author: witty
 */

#include "mysem.h"
#include "thread_queue.h"
//#include "thread_handler.h"
//#include "thread_queue.h"

#define DISABLE_INTERRUPTS() {  \
    asm("wrctl status, zero");  \
}

#define ENABLE_INTERRUPTS() {   \
    asm("movi et, 1");          \
    asm("wrctl status, et");    \
}

int semInit(semaphore * sem, int semVal)
{
	/* add your code to initialize your semaphore here */
	if(semVal >= 0){
	sem->value = semVal;
	sem->threadCount = 0;
	initThreadQueue(sem->queue);
	return 1;
	}
	return 0;
}

void semDown(semaphore * sem)
{
	/* implement your logic to perform down operation on a semaphore here */
	DISABLE_INTERRUPTS();
	//printf("Interrupts Disabled\n");
	while(sem->value == 0){
		thread_enqueue((sem->queue));
		//printf("Interrupts Enabled\n");
		ENABLE_INTERRUPTS();
		//Need to burn quantum but run afterwards to put itself back in queue
		while(get_current_running_thread()->state == BLOCKED){
			//burn quantum
		}
		DISABLE_INTERRUPTS();
	}
	DISABLE_INTERRUPTS();
	//printf("Interrupts Disabled\n");
	sem->value = sem->value - 1;
	//printf("Interrupts Enabled\n");
	ENABLE_INTERRUPTS();
}

void semUp(semaphore * sem)
{
	DISABLE_INTERRUPTS();
	//printf("Interrupts Disabled\n");

	sem->value = sem->value + 1;
	thread_dequeue(sem->queue);
	//printf("Interrupts Enabled\n");

	ENABLE_INTERRUPTS();
	/* implement your logic to perform up operation on a semaphore here */
}

unsigned int semValue(semaphore * sem)
{
	return sem->value;
}

unsigned int semThreadCount(semaphore * sem)
{
	return sem->threadCount;
}
