#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main(){
    queue *q = criarQueue();

    for (int i = 0; i < 11; i ++){
        enqueue(q, i);
    }

    puts("Teste printQueue:");
    printQueue(q);

    puts("Teste isEmpty()");
    isEmpty(q);

    puts("Teste deQueue()");
    dequeue(q);
    dequeue(q);
    printQueue(q);

    puts("Teste size()");
    size(q);

    puts("Teste clear()");
    clear(q);

    size(q);
    printQueue(q);
    isEmpty(q);
};
