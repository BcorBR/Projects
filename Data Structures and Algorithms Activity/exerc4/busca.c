#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "listaDuplamenteEncadeada.h"

Node *meioBinaria(Node *primeiro, Node *meio, Node *ultimo, int operacao, int *idx){
    int contador = 1;
    Node *aux = meio;

    // se numero eh maior que meio
    if (operacao){
        // conta nodes para encontrar indice do meio
        while (1){
            if (aux == ultimo)
                break;
            aux = aux->next;
            contador++;
        }
        // fim da busca binaria, valor nao encontrado
        if (contador == 1)
            return NULL;
        // valor de meio sera retornado
        else{
            int tmp = contador / 2;
            contador = 0;
            aux = meio;
            while (contador < tmp){
                aux = aux->next;
                contador++;
            }
            *idx += contador;
            return aux;    
        }
    }

    // se numero eh menor que meio
    else{
        // conta nodes para encontrar indice do meio
        while (1){
            if (aux == primeiro)
                break;
            aux = aux->prev;
            contador++;
        }
        // fim da busca binaria, valor nao encontrado
        if (contador == 1)
            return NULL;
        // valor de meio sera retornado
        else{
            int tmp = contador / 2;
            contador = 0;
            aux = meio;
            while (contador < tmp){
                aux = aux->prev;
                contador++;
            }
            *idx -= contador;
            return aux;    
        }
    }
}

Node *buscaBinaria(Lista *li, Node *primeiro, Node *meio, Node *ultimo, int valor, int *idx){
    Node *resultado = (Node *)malloc(sizeof(Node));
    if (resultado == NULL){
        printf("erro ao alocar Node resultado\n");
        exit(1);
    }

    // comparacoes
    if (valor < meio->data){
        Node *novoMeio = meioBinaria(primeiro, meio, ultimo, 1, idx);
        
        // se ponteiro retornado nao for NULL
        if (novoMeio)
            resultado = buscaBinaria(li, meio->next, novoMeio, ultimo, valor, idx);
        // se for NULL (busca acabou sem sucesso)
        else{
            *idx = -1;
            return NULL;
        }
    }

    else if (valor > meio->data){
        Node *novoMeio = meioBinaria(primeiro, meio, ultimo, 0, idx);
        
        // se ponteiro retornado nao for NULL
        if (novoMeio)
            resultado = buscaBinaria(li, primeiro, novoMeio, meio->prev, valor, idx);
        // se for NULL (busca acabou sem sucesso)
        else{
            *idx = - 1;
            return NULL;
        }
    }
    return resultado; 
}

// executa a troca de valores
void swap(Node* x, Node* y){
    int tmp = x->data;
    x->data = y->data;
    y->data = tmp;
}

// prev direçao head
// metodo insertion
void ordenar(Lista *li, int size){
    Node *right = li->head->next;
    Node *left = li->head;

    for (right = li->head->next; right != NULL; right = right->next){
        for (left = right->prev; left != NULL; left = left->prev){
            if (left->data < left->next->data)
                swap(left, left->next);
            else
                break;
        }
    }
    li->ordenado = 1; 
};