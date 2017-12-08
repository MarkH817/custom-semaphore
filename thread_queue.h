/*
    Description:
    Functions used to implment a thread queue and its operations
*/

typedef struct thread_element
{
    void                  *data;
    struct thread_element *next;
} T_type;

typedef struct thread_queue_type
{
    T_type              *head;
    T_type              *tail;
    unsigned int        size;
} TQ_type;

void initThreadQueue(TQ_type queue);

void enqueue(TQ_type queue, void *data);

void *dequeue(TQ_type queue);

unsigned int getQsize(TQ_type queue);
