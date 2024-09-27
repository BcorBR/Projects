#ifndef STACK_H
#define STACK_H

typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct stack{
    node *top;
} stack;

stack *criar_stack();
void push(stack *s, int num);
void pop(stack *s);
int isEmpty(stack *s);
void top(stack *s);
void clear(stack *s);
void printStack(stack *s);

#endif // STACK_H