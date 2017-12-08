#include <stdio.h>
#include "thread_handler.h"
#include "thread_queue.h"

void initThreadQueue(TQ_type *queue) {
    // Initialize queue variable
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void releaseAll(TQ_type *queue) {
    unsigned int size = queue->size;
    unsigned int i;

    for (i = 0; i < size; i++) {
        dequeue(queue);
    }
}

void enqueue(TQ_type *queue)
{
    T_type  *elem;

    elem = (T_type *) malloc(sizeof(T_type));

    if (elem == NULL)
    {
        printf("Unable to allocate space!\n");
        exit(1);
    }

    elem->data = get_current_running_thread();
    elem->next = NULL;

    if (queue->head == NULL) {
        queue->head = elem;
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
        elem->data->state = RUNNING;

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
