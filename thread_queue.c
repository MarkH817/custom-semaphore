#include <stdio.h>
#include "thread_handler.h"
#include "thread_queue.h"

void initThreadQueue(TQ_type *queue) {
    // Initialize queue variable
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void thread_enqueue(TQ_type *queue)
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
    printf("Thread is getting enqueued %d\n", elem->data->tid);

    queue->tail = elem;

    queue->size++;
}

void thread_dequeue(TQ_type *queue)
{
    T_type  *elem;
    void    *data = NULL;
    printf("Releasing All\n");
    while(queue->size != 0) {
        elem = queue->head;
        if (queue->size == 1) {
            queue->tail = NULL;
        }

        // Unblock thread
        elem->data->state = RUNNING;
        printf("Thread is getting dequeued %d\n", elem->data->tid);
        queue->head = queue->head->next;

        queue->size--;
        data = elem->data;
        free(elem);
    }

}

unsigned int thread_getQsize(TQ_type *queue)
{
    return queue->size;
}
