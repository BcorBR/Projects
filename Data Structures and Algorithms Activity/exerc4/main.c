#include <stdlib.h>
#include <stdio.h>

#include "busca.h"
#include "listaDuplamenteEncadeada.h"

int main(){
    Lista *li = criarLista();
    
    // teste 1
    printf("imprime 5, 4, 2, 1, 0\n");
    insert(li, 2, 0);
    insert(li, 0, 1);
    insert(li, 1, 2);
    insert(li, 4, 3);
    insert(li, 5, 4);

    ordenar(li, 5);

    printLista(li);
    puts("\n");

    // teste 2
    // lista = 5, 4, 2, 1, 0
    printf("deve imprimir 0, 1, -1, 3, 4\n");
    printf("%d ", busca(li, 5));
    printf("%d ", busca(li, 4));
    printf("%d ", busca(li, 3));
    printf("%d ", busca(li, 2));
    printf("%d ", busca(li, 1));
    printf("%d ", busca(li, 0));
    puts("\n");

    // teste 3
    printf("deve imprimir 5 e 5\n");
    insert(li, -1, 5);
    printf("%d ", busca(li, -1));
    ordenar(li, 6);
    printf("%d ", busca(li, -1));
    puts("\n");

    // teste 4
    printf("deve imprimir -1 -1\n");
    printf("%d ", busca(li, -10));
    printf("%d ", busca(li, 10));
    puts("\n");
    
    return 0;
}