#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "thread_handler.h"

static Q_type queue = {NULL, NULL, 0};

void enqueue(void *data)
{
    E_type  *elem;

    if ((elem = (E_type *)malloc(sizeof(E_type))) == NULL)
    {
        printf("Unable to allocate space!\n");
        exit(1);
    }
    elem->data = data;
    elem->next = NULL;

    if (queue.head == NULL)
        queue.head = elem;
    else
        queue.tail->next = elem;
    queue.tail = elem;

    queue.size++;
}

void *dequeue()
{
    E_type  *elem;
    void    *data = NULL;

    if (queue.size != 0)
    {
        elem = queue.head;
        if (queue.size == 1)
            queue.tail = NULL;
        queue.head = queue.head->next;

        queue.size--;
        data = elem->data;
        free(elem);
    }

    return data;
}

unsigned int getQsize()
{
    return queue.size;
}


void enqueueT(T_type *Tqueue, tcb *data)
{
    E_type  *elem;

    if ((elem = (E_type *)malloc(sizeof(E_type))) == NULL)
    {
        printf("Unable to allocate space!\n");
        exit(1);
    }
    elem->data = data;
    elem->next = NULL;

    if (Tqueue->head == NULL)
        Tqueue->head = elem;
    else
        Tqueue->tail->next = elem;
    Tqueue->tail = elem;

    Tqueue->size++;
}

void *dequeueT(T_type *Tqueue)
{
    E_type  *elem;
    void    *data = NULL;

    if (Tqueue->size != 0)
    {
        elem = Tqueue->head;
        if (Tqueue->size == 1)
            Tqueue->tail = NULL;
        Tqueue->head = Tqueue->head->next;

        Tqueue->size--;
        data = elem->data;
        free(elem);
    }

    return data;
}

unsigned int getTsize(T_type *Tqueue)
{
    return Tqueue->size;
}


void *release(T_type *Tqueue)
{
	int i;
	for (i =0; i<Tqueue->size; i++){
		mythread_start(Tqueue->head->data);
		dequeueT(Tqueue);
	}

}
