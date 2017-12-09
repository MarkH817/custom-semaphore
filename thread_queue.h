/*
    Description:
    Functions used to implement a thread queue and its operations
*/
#include "thread_handler.h"

#ifndef THREAD_QUEUE_H
#define THREAD_QUEUE_H

typedef struct thread_element
{
    tcb *data;
    struct thread_element *next;
} T_type;

typedef struct thread_queue_type
{
    T_type              *head;
    T_type              *tail;
    unsigned int        size;
} TQ_type;

void initThreadQueue(TQ_type *queue);

void thread_enqueue(TQ_type *queue);

void thread_dequeue(TQ_type *queue);

unsigned int thread_getQsize(TQ_type *queue);

#endif /* GRANDPARENT_H */

