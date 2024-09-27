#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


queue *criarQueue(){
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL){
        puts("Erro na alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    else{
        q->front = NULL;
        q->rear = NULL;
    };
    return q;
}

void enqueue(queue *q, int num){
    // alocar para node, conceder value, front, near e next
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL){
        puts("Erro na alocacao de memoria");
        exit(EXIT_FAILURE);
    }

    new_node->value = num;
    new_node->next = NULL;

    if (q->rear != NULL){
        q->rear->next = new_node;
    };
    q->rear = new_node;

    if (q->front == NULL){
        q->front = new_node;
    };
    };

void isEmpty(queue *q){
    if (q->front == NULL){
        puts("A queue esta vazia");
    }
    else{
        puts("A queue nao esta vazia");
    };
}

int dequeue(queue *q){
    node *fr = q->front;
    int val = q->front->value;
    q->front = q->front->next;

    printf("%d\n", val);
    free(fr);

    return val;
};

node *front(queue *q){
    printf("%d\n", q->front->value);
    return q->front;
};

int size(queue *q){
    int count = 0;
    if (q->rear == NULL){
        return 0;
    }

    node *tmp = q->front;
    while ((tmp != NULL)){
        count++;
        tmp = tmp->next;

    };
    printf("%d\n", count);

    return count;
};

void clear (queue *q){
    while (q->front != NULL ){
        node *tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    };

};

void printQueue(queue *q){
    if (q->front == NULL){
        return;
    }
    node *tmp = q->front;

    do{
        printf("%d, ", tmp->value);
        tmp = tmp->next;
    } while ((tmp != NULL));
    puts("");
};
