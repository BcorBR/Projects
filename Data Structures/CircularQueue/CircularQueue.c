#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CircularQueue.h"


void init_queue(queue *q, int max_size){
    q->size = max_size;
    q->values = (int *)malloc(max_size * sizeof(int));
    q->num_entries = 0;
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue *q){
    return !(q->num_entries);
}

bool queue_full(queue *q){
    return (q->num_entries == q->size);
}

void queue_destroy(queue *q){
    free(q->values);
    free(q);   
}

bool enqueue(queue *q, int value){
    if (queue_full(q))
        return false;
    
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;
    
    return true;
}

int *dequeue(queue *q){
    if (queue_empty(q))
        return NULL;
    
    int *val;
    
    val = &q->values[q->head];
    
    q->head = (q->head + 1) % q->size;
    q->num_entries--;

    return val;
}