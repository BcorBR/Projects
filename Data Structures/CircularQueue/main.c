#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CircularQueue.h"

#define QUEUE_EMPTY


int main(){
    queue q;

    init_queue(&q, 5);
    enqueue(&q, 2);
    
    for (int i = 0; i < 4; i++)
        enqueue(&q, i);

    for (int i = 5; i > 0; i--)
        dequeue(&q);
    
    if (queue_empty(&q))
        printf("queue empty\n");
    if (queue_full(&q))
        printf("queue full\n");

    return 0;
}