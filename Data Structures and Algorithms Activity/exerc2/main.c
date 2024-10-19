#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int topA;
    int topB;

    int capacity;
    int *vetor;
    // quantidade de elementos inseridos
    int entries;
} pilha_dupla;

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

int main(){
    pilha_dupla *pd = criarPilhaDupla(10);

    for (int i = 1; i < 4; i++){
        pushA(pd, i);    
        pushB(pd, i*4);
    }

    // teste 1
    printf("Deve imprimir 3, 2, 1 // 12, 8, 4\n");
    imprimirA(pd);
    imprimirB(pd);
    puts("");

    // teste 2
    printf("Deve imprimir 2, 1 // 8, 4\n");
    popA(pd);
    popB(pd);

    imprimirA(pd);
    imprimirB(pd);
    puts("");

    // teste 3
    printf("Deve dar 2 underflows pelo pop() e dois pelo imprimir()\n");
    for (int i = 0; i < 3; i++){
        popA(pd);
        popB(pd);
    }

    imprimirA(pd);
    imprimirB(pd);
    puts("");

    // teste 4
    printf("Deve dar 2 overflows pelo push() e imprimir \n5, 4, 3, 2, 1 // 20, 16, 12, 8, 4\n");
    for (int i = 1; i < 7; i++){
        pushA(pd, i);    
        pushB(pd, i*4);
    }

    imprimirA(pd);
    imprimirB(pd);
    puts("");

    // teste 5
    printf("Deve dar underflow e imprimir 20, 16, 12, 8, 4\n");
    clearA(pd);

    imprimirA(pd);
    imprimirB(pd);
    puts("");

    // teste 6
    printf("deve dar 2 underflow\n");
    clearB(pd);

    imprimirA(pd);
    imprimirB(pd);
    puts("");

    // teste 7
    printf("Deve dar 2 undeflow pelo clear() e 2 pelo imprimir()\n");
    clearA(pd);
    clearB(pd);

    imprimirA(pd);
    imprimirB(pd);

    return 0;
}
