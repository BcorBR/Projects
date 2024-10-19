#include <stdbool.h>

#include "pilhaDinamica.h"
#include "fila_estaticaCircular.h"
#include "balanceamento.h"

// retorna 1 se a contagem ainda eh valida e 0 se nao eh balanceado
bool contagem(char *carac, int *par, int *col, int *cha, Pilha *p){
    if (*carac == '('){
        *par += 1;
        push(p, *carac);
    }
    else if (*carac == '['){
        *col += 1;
        push(p, *carac);
    }
    else if (*carac == '{'){
        *cha += 1;
        push(p, *carac);
    }

    // avalia os que fechao para evitar arranjos errados
    else if (*carac == ')'){
        if (!isEmptyP(p) && pop(p) == '('){
            *par -= 1;
            return true;
        }
        else
            return false;
    }
    else if (*carac == ']'){
        if (!isEmptyP(p) && pop(p) == '['){
            *col -= 1;
            return true;
        }
        else
            return false;
    }
    else if (*carac == '}'){
        if (!isEmptyP(p) && pop(p) == '{'){
            *cha -= 1;
            return true;
        }
        else
            return false;
    }
 
    return true;
}

// A funcao recebe a fila com os dados a serem analisados e 
// uma pilha vazia utilizada para a avaliacao
bool verificaBalanceamento(Fila *f, Pilha *p){
    // contagem de parenteses colchetes e chaves
    int par = 0, col = 0, cha = 0;
    bool invalid = false;

    int size = getSize(f);
    p->tamanho = size;

    // fila backup
    char *arr = (char *)malloc(sizeof(size));
    for (int i = 0; i < size; i++)
        arr[i] = dequeue(f);

    for (int i = 0; i < size; i ++){
        if (!contagem(&arr[i], &par, &col, &cha, p)){
            invalid = true;
            break;
        }
    }

    // restaura fila
    for (int i = 0; i < size; i++)
        enqueue(f, arr[i]);
    
    free(arr);

    // avalia se abertos e fechados sao iguais
    if (par == 0 && col == 0 && cha == 0 && invalid == false)
        return true;
    return false;
}
