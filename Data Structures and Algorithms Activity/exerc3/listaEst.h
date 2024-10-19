#include "fila_estaticaCircular.h"

typedef struct{
    int *vetor;
    int *sucessor;
    int tamanho;
    int head;
    int tail;

    // guarda quantos elementos estam adicionados
    int entries;
    
    // guarda os indices vazios do vetor
    Fila *vazios;
} listaEst;

listaEst *criarListaEst(int tam);

// insere valor val na posicao pos
void inserir(listaEst *li, int val, int pos);

int remover(listaEst *li, int pos);

int buscar(listaEst *li, int val);

int size(listaEst *li);

void clear(listaEst *li);

// checa se indice `val` esta no array
int checarArray(int *arr, int tam, int val);

void imprimirLista(listaEst *li);