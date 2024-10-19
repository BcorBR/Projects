#include <stdlib.h>
#include <stdio.h>

#include "pilhaDupla.h"

pilha_dupla *criarPilhaDupla(int cpt){
    pilha_dupla *pd = (pilha_dupla *)malloc(sizeof(pilha_dupla));
    pd->capacity = cpt;
    pd->entries = 0;

    pd->vetor = (int *)malloc(cpt* sizeof(int));

    // posiciona pilhas
    pd->topA = -1;
    pd->topB = cpt;

    return pd;
}

void pushA(pilha_dupla *pd, int valor){
    if (pd->entries == pd->capacity){
        printf("Erro, overflow\n");
        return;
    }
    
    // incrementa posicao top e insere valor nela
    pd->topA++;
    pd->vetor[pd->topA] = valor;
    pd->entries++;
}

void pushB(pilha_dupla *pd, int valor){
    if (pd->entries == pd->capacity){
        printf("Erro, overflow\n");
        return;
    }

    // incrementa posicao top e insere valor nela
    pd->topB--;
    pd->vetor[pd->topB] = valor;
    pd->entries++;
}

int popA(pilha_dupla *pd){
    if (pd->topA == -1){
        printf("Erro, underflow\n");
        return -99999999;
    }

    pd->topA--;
    pd->entries--;

    //retorna valor removido
    return pd->vetor[pd->topA + 1];
}

int popB(pilha_dupla *pd){
    if (pd->topB == pd->capacity){
        printf("Erro, underflow\n");
        return -99999999;
    }

    pd->topB++;
    pd->entries--;

    //retorna valor removido
    return pd->vetor[pd->topB - 1];
}

void clearA(pilha_dupla *pd){
    if (pd->topA == -1){
        printf("A pilha ja esta vazia\n");
        return;
    }

    // exclui numero da quantidade de elementos na pilha A de entries
    pd->entries -= pd->topA + 1;
    pd->topA = -1;
}

void clearB(pilha_dupla *pd){
    if (pd->topB == pd->capacity){
        printf("A pilha ja esta vazia\n");
        return;
    }

    // exclui numero da quantidade de elementos na pilha A de entries
    pd->entries -= pd->capacity - pd->topB;
    pd->topB = pd->capacity;
}

void imprimirA(pilha_dupla *pd){
    if (pd->topA == -1){
        printf("A pilha esta vazia\n");
        return;
    }

    for (int i = pd->topA; i > -1; i--)
        printf("%d ", pd->vetor[i]);
    puts("");
}

void imprimirB(pilha_dupla *pd){
    if (pd->topB == pd->capacity){
        printf("A pilha esta vazia\n");
        return;
    }

    for (int i = pd->topB; i < pd->capacity; i++)
        printf("%d ", pd->vetor[i]);
    puts("");
}
