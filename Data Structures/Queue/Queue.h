#ifndef QUEUE_H
#define QUEUE_H

typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct queue{
    struct node *front;
    struct node *rear;
} queue;

queue *criarQueue();
void enqueue(queue *q, int num);
void isEmpty(queue *q);
int dequeue(queue *q);
node *front(queue *q);
int size(queue *q);
void clear (queue *q);
void printQueue(queue *q);

#endif // QUEUE_H