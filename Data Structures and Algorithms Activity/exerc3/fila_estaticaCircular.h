#ifndef FILA_ESTATICACIRCULAR_H
#define FILA_ESTATICACIRCULAR_H

typedef struct {
    int capacity;
    int *data;
    int front;
    int rear;
    int size;
} Fila;

// Função para inicializar a fila
void criarFila(Fila *fila, int capacity);

// Função para adicionar um elemento na fila
void enqueue(Fila *fila, int data);

// Função para remover um elemento da fila
int dequeue(Fila *fila);

// Função para obter o tamanho da fila
int getSize(Fila *fila);

// Função para verificar se a fila está vazia
int isEmptyF(Fila *fila);

// Função para verificar se a fila está cheia
int isFull(Fila *fila);

// Função para obter o primeiro elemento da fila
int getFront(Fila *fila);

// Função para limpar a fila
void clearF(Fila *fila);

// Função para imprimir a fila
void imprimir(Fila *fila);

#endif // FILA_ESTATICACIRCULAR_H
