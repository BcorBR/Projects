#include <stdbool.h>

#include "pilhaDinamica.h"
#include "fila_estaticaCircular.h"

// retorna 1 se a contagem ainda eh valida e 0 se nao eh balanceado
bool contagem(char *carac, int *par, int *col, int *cha, Pilha *p);

// A funcao recebe a fila com os dados a serem analisados e 
// uma pilha vazia utilizada para a avaliacao
bool verificaBalanceamento(Fila *f, Pilha *p);