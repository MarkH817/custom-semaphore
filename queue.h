/*
    Name:   queue.h
    Author: Dongyuan Zhan
    Date:   11/20/2010

Description:
    Functions used to implment a queue and its operations
*/

typedef struct element_type
{
    void                *data;
    struct element_type *next;
} E_type;

typedef struct queue_type
{
    E_type              *head;
    E_type              *tail;
    unsigned int        size;
} Q_type;

typedef struct thread_queue
{
    E_type              *head;
    E_type              *tail;
    unsigned int        size;
}T_type;
void enqueue(void *data);

void *dequeue();

void enqueueT(T_type *t, tcb *data);

void *dequeueT(T_type *t);

unsigned int getTsize(T_type *t);

unsigned int getQsize();

void *release(T_type *t);
