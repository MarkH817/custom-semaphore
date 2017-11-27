/*
 * mysem.c
 *
 *  Created on: Nov 12, 2017
 *      Author: witty
 */

#include "mysem.h"

int semInit(semaphore * sem, int semVal)
{
	/* add your code to initialize your semaphore here */
	return 1;
}

void semDown(semaphore * sem)
{
	/* implement your logic to perform down operation on a semaphore here */
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


