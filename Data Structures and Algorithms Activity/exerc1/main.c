#include <stdbool.h>

#include "pilhaDinamica.h"
#include "fila_estaticaCircular.h"
#include "balanceamento.h"


int main(){
    Fila f;
    Pilha *p = criarPilha();
    char arrF[7] = {'(', ')', '[', ')', ']', '{', '}'};
    char arrV[8] = {'(', '(', '[', ']', ')', ')', '{', '}'};
    char arrF2[6] = {'(', '(', '[', ')', ']', ')'};

    criarFila(&f, 7);
    // teste 1
    printf("deve imprimir false\n");
    for (int i = 0; i < 7; i++)
        enqueue(&f, arrF[i]);

    if (verificaBalanceamento(&f, p) == true)
        printf("TRUE\n");
    else   
        printf("FALSE\n");
    puts("\n");

    // teste 2
    printf("deve imprimir false\n");
    clearF(&f);
    f.capacity = 8;
    for (int i = 0; i < 8; i++)
        enqueue(&f, arrV[i]);

    if (verificaBalanceamento(&f, p) == true)
        printf("TRUE\n");
    else   
        printf("FALSE\n");
    puts("\n");

    //teste 3
    printf("deve imprimir true\n");
    clearF(&f);
    f.capacity = 6;
    for (int i = 0; i < 6; i++)
        enqueue(&f, arrF2[i]);

    if (verificaBalanceamento(&f, p) == true)
        printf("TRUE\n");
    else   
        printf("FALSE\n");
    puts("\n");

    return 0;
}