/*
 * mysem.c
 *
 *  Created on: Nov 12, 2017
 *      Author: witty
 */

#include "mysem.h"
#include "thread_handler.h"
int semInit(semaphore * sem, int semVal)
{
	/* add your code to initialize your semaphore here */
	if(semVal >= 0){
	sem->value = semVal;
	sem->threadCount = 0;
	return 1;
	}
	return 0;
}

void semDown(semaphore * sem)
{
	/* implement your logic to perform down operation on a semaphore here */
	DISABLE_INTERRUPTS();
	while(sem->value == 0){
		enqueueT(&(sem->queue), get_current_running_thread());
		ENABLE_INTERRUPTS();
	}
	DISABLE_INTERRUPTS();
	sem->value = sem->value - 1;
	ENABLE_INTERRUPTS();
}

void semUp(semaphore * sem)
{
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
