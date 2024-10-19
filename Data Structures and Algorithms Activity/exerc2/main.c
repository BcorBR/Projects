#include <stdlib.h>
#include <stdio.h>

#include "pilhaDupla.h"

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
