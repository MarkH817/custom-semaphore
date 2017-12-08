#include <stdio.h>
#include "thread_handler.h"
#include "thread_queue.h"

void initThreadQueue(TQ_type *queue) {
    // Initialize queue variable
    queue->head = null;
    queue->tail = null;
    queue->size = 0;
}

void enqueue(TQ_type *queue, void *data)
{
    T_type  *elem;

    elem = (T_type *) malloc(sizeof(T_type));

    if (elem == NULL)
    {
        printf("Unable to allocate space!\n");
        exit(1);
    }

    elem->data = data;
    elem->next = NULL;

    if (queue.head == NULL) {
        queue.head = elem;
    }
    else {
        queue->tail->next = elem;
    }

    // Block added thread
    mythread_block(get_current_running_thread());

    queue->tail = elem;

    queue->size++;
}

void *dequeue(TQ_type *queue)
{
    T_type  *elem;
    void    *data = NULL;

    if (queue.size != 0) {
        elem = queue->head;
        if (queue->size == 1) {
            queue->tail = NULL;
        }

        // Unblock thread
        elem->state = RUNNING;

        queue->head = queue->head->next;

        queue->size--;
        data = elem->data;
        free(elem);
    }

    return data;
}

unsigned int getQsize(TQ_type *queue)
{
    return queue->size;
}
