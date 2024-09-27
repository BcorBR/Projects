#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


stack *criar_stack(){
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {
        printf("Houve um erro de alocacao");
        exit(EXIT_FAILURE);
    };
    s->top = NULL;
    return s;
};

void push(stack *s, int num){
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL){
        printf("Houve um erro de alocacao");
        exit(EXIT_FAILURE);
    };
    new_node->value = num;
    new_node->next = s->top;
    s->top = new_node;
};

void pop(stack *s){
    // tirar o node top do stack e dar top para o pr�ximo
    if (isEmpty(s) == 0){
        node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    else{
        printf("O stack ja esta vazio");
        exit(EXIT_FAILURE);
    };
    printf("%d", s->top->value);
}

int isEmpty(stack *s){
    if (s->top != NULL){
        return 0;
    }
    else{
        return 1;
    };
}

void top(stack *s){
    if (isEmpty(s)){
        printf("O stack esta vazio");
        exit(EXIT_FAILURE);
    }
    else{
        printf("%d\n", s->top->value);
    }
};

void clear(stack *s){
    // temp = node->next... excluir node... tmep = node-> next...
    if (isEmpty(s)){
        printf("O stack esta vazio");
        exit(EXIT_FAILURE);
    }
    else{
        while (s->top != NULL){
            node *tmp = s->top->next;
            free(s->top);
            s->top = tmp;
        };
    };
};

void printStack(stack *s){
    if (isEmpty(s)){
        printf("O stack esta vazio");
        exit(EXIT_FAILURE);
    }
    else{
        node *first = s->top;
        printf("%d - ", first->value); 
        node *tmp = first->next;

        while (tmp != NULL){
            tmp = first->next;
            first = tmp;
        if (tmp != NULL){
            printf("%d - ", tmp->value);
        };
        };
        puts("");
    };
};