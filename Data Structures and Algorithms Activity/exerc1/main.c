#include <stdbool.h>

#include "pilhaDinamica.h"
#include "fila_estaticaCircular.h"

// retorna 1 se a contagem ainda eh valida e 0 se nao eh balanceado
int contagem(char *carac, int *par, int *col, int *cha, Pilha *p){
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
            return 1;
        }
        else
            return 0;
    }
    else if (*carac == ']'){
        if (!isEmptyP(p) && pop(p) == '['){
            *col -= 1;
            return 1;
        }
        else
            return 0;
    }
    else if (*carac == '}'){
        if (!isEmptyP(p) && pop(p) == '{'){
            *cha -= 1;
            return 1;
        }
        else
            return 0;
    }
 
    return 1;
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

int main(){
    Fila f;
    Pilha *p = criarPilha();
    char arrF[7] = {'(', ')', '[', ')', ']', '{', '}'};
    char arrV[8] = {'(', '(', '[', ']', ')', ')', '{', '}'};
    char arrF2[6] = {'(', '(', '[', ')', ']', ')'};

    criarFila(&f, 7);
    // teste 1
    for (int i = 0; i < 7; i++)
        enqueue(&f, arrF[i]);

    if (verificaBalanceamento(&f, p) == true)
        printf("TRUE\n");
    else   
        printf("FALSE\n");

    // teste 2
    clearF(&f);
    f.capacity = 8;
    for (int i = 0; i < 8; i++)
        enqueue(&f, arrV[i]);

    if (verificaBalanceamento(&f, p) == true)
        printf("TRUE\n");
    else   
        printf("FALSE\n");

    //teste 3
    clearF(&f);
    f.capacity = 6;
    for (int i = 0; i < 6; i++)
        enqueue(&f, arrF2[i]);

    if (verificaBalanceamento(&f, p) == true)
        printf("TRUE\n");
    else   
        printf("FALSE\n");

    return 0;
}