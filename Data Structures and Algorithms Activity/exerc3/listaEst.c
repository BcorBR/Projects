#include <stdlib.h>
#include <stdio.h>

#include "fila_estaticaCircular.h"
#include "listaEst.h"

listaEst *criarListaEst(int tam){
    listaEst *li = (listaEst *)malloc(sizeof(listaEst));

    li->tamanho = tam;
    li->entries = 0;

    // aloca memoria para vetor sucessor
    li->sucessor = (int *)malloc(sizeof(int) * tam);
    if (li->sucessor == NULL){
        printf("erro ao alocar array sucessor\n");
        exit(1);
    }
    // aloca mem pra vetor vetor
    li->vetor = (int *)malloc(sizeof(int) * tam);
    if (li->vetor == NULL){
        printf("erro ao alocar vetor real\n");
        exit(1);
    }
    // aloca fila de indices vazios
    li->vazios = (Fila *)malloc(sizeof(Fila));
    if (li->vazios == NULL){
        printf("erro ao alocar memoria para fila vazios\n");
        exit(1);
    }

    for (int i = 0; i < tam; i++)
        li->sucessor[i] = -1;
    criarFila(li->vazios, tam);

    // configura espacos vazios
    for (int i = 0; i < tam; i++)
        enqueue(li->vazios, i);
    
    // configura sucessores
    for (int i = 0; i < tam; i++)
        li->sucessor[i] = -1;

    return li;
}

// insere valor val na posicao pos
void inserir(listaEst *li, int val, int pos){
    // checa se vetor contem espaco
    if (li->entries == li->tamanho){
        printf("Erro, lista cheia\n");
        return;
    }

    // checa se posicao eh alem da permitida
    if (pos > li->entries || pos > li->tamanho - 1 || pos < 0){
        printf("Erro, posicao invalida, selecione uma menor\n");
        return;
    }

    // coloca valor no vetor nao sequencial e salva o indice
    int iReal = dequeue(li->vazios);
    li->vetor[iReal] = val;

    // se vetor esta vazio
    if (li->entries == 0){
        li->head = iReal;
        li->tail = iReal;
        li->entries++;     
        return;
    }

    // checa se posicao é primeira a no vetor
    if (pos == 0){
        li->sucessor[iReal] = li->head;
        li->head = iReal;
        li->entries++;     
        return;
    }
   
    int contador = 0;
    int idx = li->head;
    while (contador < pos - 1){
        contador += 1;
        idx = li->sucessor[idx];
    }

    int tmp = li->sucessor[idx];
    li->sucessor[idx] = iReal;
    li->sucessor[iReal] = tmp;

    // se posicao for a ultima no vetor    
    if (pos == li->entries){
        li->sucessor[iReal] = -1;
        li->tail = iReal;
    }

    li->entries++;
}

int remover(listaEst *li, int pos){
    // checa se posicao eh alem da permitida
    if (pos > li->entries - 1 || pos < 0){
        printf("Erro, posicao invalida\n");
        return - 999999;
    }

    // checa se vetor contem elementos
    if (li->entries == 0){
        printf("Erro, lista vazia\n");
        return - 999999;
    }

    // se remover o head
    if (pos == 0){
        //salva valor de elemento para retornar
        int tmp = li->vetor[(li->head)];

        enqueue(li->vazios, li->head);
        li->head = li->sucessor[(li->head)];

        li->entries--;

        return tmp;
    }


    int contador = 0;
    int idx = li->head;
    while (contador < pos - 1){
        contador += 1;
        idx = li->sucessor[idx];
    }

    // se remover o tail
    if (pos == li->entries - 1){
        // salva valor do elemento para retornar
        int tmp = li->vetor[li->tail];

        enqueue(li->vazios, li->tail);
        li->tail = idx;
        li->sucessor[idx] = -1;

        li->entries--;

        return tmp;
    }

    // *associa* ((valor de sucessao) de um elemento antes do escolhido) ao ((valor de sucessao) do escolhido)
    int iReal = li->sucessor[idx];
    li->sucessor[idx] = li->sucessor[li->sucessor[idx]];
    // adiciona indice vazio na fila
    enqueue(li->vazios, iReal);
    li->entries--;

    return li->vetor[iReal];
}

int buscar(listaEst *li, int val){
    int contador = 0;
    int idx =  (li->head);

    while (idx != -1){
        if (li->vetor[idx] != val){
            contador++;
            idx = li->sucessor[idx];
        }
        else
            return contador;
    }
    printf("Esse valor nao esta na lista\n");
    return -1; 
}

int size(listaEst *li){
    return li->entries;
}

void clear(listaEst *li){
    clearF(li->vazios);

    for (int i = 0; i < li->tamanho; i++){
        li->sucessor[i] = -1;
        enqueue(li->vazios, i);
    }

    li->head = -1;
    li->tail = -1;
    li->entries = 0;
}

// checa se indice `val` esta no array
int checarArray(int *arr, int tam, int val){
    for (int i = 0; i < tam; i++){
        if (val == arr[i])
            return 1;
    }
    return 0;
}

void imprimirLista(listaEst *li){
    if (li->entries == 0){
        printf("A lista esta vazia\n");
        return;
    }
    // grava os indices validos do vetor
    int *arr = (int *)malloc(li->entries*sizeof(int));
    if (arr == NULL){
        printf("erro ao alocar array de impressao\n");
        exit(1);
    }

    printf("Lista real:\n");
    int idx = li->head;
    for (int i = 0; i < li->entries; i++){
        printf("%d ", li->vetor[idx]);
        arr[i] = idx;
        idx = li->sucessor[idx];
    }

    printf("Head: %d, Tail: %d ", li->head, li->tail);

    // printa lista nao sequencial
    for (int i = 0; i < li->tamanho; i++){
        
        // se indice eh valido
        if (checarArray(arr, li->entries, i))
            printf("(%d, %d) ", li->vetor[i], li->sucessor[i]);
        else
            printf("(-, -) ");
    }
}