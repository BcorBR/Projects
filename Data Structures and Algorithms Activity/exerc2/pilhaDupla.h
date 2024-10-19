#ifndef PILHADUPLA_H
#define PILHADUPLA_H

typedef struct {
    int topA;
    int topB;

    int capacity;
    int *vetor;
    // quantidade de elementos inseridos
    int entries;
} pilha_dupla;

pilha_dupla *criarPilhaDupla(int cpt);

void pushA(pilha_dupla *pd, int valor);

void pushB(pilha_dupla *pd, int valor);

int popA(pilha_dupla *pd);

int popB(pilha_dupla *pd);

void clearA(pilha_dupla *pd);

void clearB(pilha_dupla *pd);

void imprimirA(pilha_dupla *pd);

void imprimirB(pilha_dupla *pd);

#endif // PILHADUPLA_H