/*
 * mysem.h
 *
 *  Created on: Nov 12, 2017
 *      Author: witty
 */

#ifndef MYSEM_H_
#define MYSEM_H_

struct mySem{
	int threadCount;
	int value;
	/* You need to add your blocking queue in this struct. */
};

typedef struct mySem semaphore;

int semInit(semaphore *, int semValue);
void semDown(semaphore *);
void semUp(semaphore *);
unsigned int semValue(semaphore *);
unsigned int semThreadCount(semaphore *);


#endif /* MYSEM_H_ */
