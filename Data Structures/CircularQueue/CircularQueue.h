#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdbool.h>


typedef struct {
    int *values;
    int head, tail, num_entries, size;

} queue;

void init_queue(queue *q, int max_size);
bool queue_empty(queue *q);
bool queue_full(queue *q);
void queue_destroy(queue *q);
bool enqueue(queue *q, int value);
int *dequeue(queue *q);

#endif // CIRCULARQUEUE_H