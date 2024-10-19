#ifndef BUSCA_H
#define BUSCA_H

#include "listaDuplamenteEncadeada.h"

// acha o node do meio
Node *meioBinaria(Node *primeiro, Node *meio, Node *ultimo, int operacao, int *idx);

Node *buscaBinaria(Lista *li, Node *primeiro, Node *meio, Node *ultimo, int valor, int *idx);

// executa a troca de valores
void swap(Node* x, Node* y);

// metodo insertion
void ordenar(Lista *li, int size);

#endif // BUSCA_H