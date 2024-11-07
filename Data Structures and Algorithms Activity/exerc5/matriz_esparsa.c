#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

// Função para criar uma nova matriz esparsa
MatrizEsparsa* criar_matriz(int linhas, int colunas) {
    // Aloca memória para a estrutura da matriz
    MatrizEsparsa* matriz = (MatrizEsparsa*)malloc(sizeof(MatrizEsparsa));
    matriz->linhas = linhas;
    matriz->colunas = colunas;

    // Aloca memória para os arrays de ponteiros das linhas e colunas
    matriz->linhas_cabeca = (No**)calloc(linhas, sizeof(No*));
    matriz->colunas_cabeca = (No**)calloc(colunas, sizeof(No*));

    return matriz;
}

// Função para inserir um elemento na matriz
void inserir(MatrizEsparsa* matriz, int linha, int coluna, int valor) {
    linha--; // Ajuste para indexação baseada em 0
    coluna--;

    // Verifica se a posição é válida
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("Posição inválida!\n");
        return;
    }

    // Se o valor for zero, remove o elemento (se existir)
    if (valor == 0) {
        remover(matriz, linha + 1, coluna + 1);
        return;
    }

    // Cria um novo nó
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->prox_linha = NULL;
    novo->prox_coluna = NULL;

    // Insere na lista de linhas
    if (matriz->linhas_cabeca[linha] == NULL || matriz->linhas_cabeca[linha]->coluna > coluna) {
        novo->prox_linha = matriz->linhas_cabeca[linha];
        matriz->linhas_cabeca[linha] = novo;
    } else {
        No* atual = matriz->linhas_cabeca[linha];
        while (atual->prox_linha != NULL && atual->prox_linha->coluna < coluna) {
            atual = atual->prox_linha;
        }
        if (atual->coluna == coluna) {
            atual->valor = valor;
            free(novo);
            return;
        }
        novo->prox_linha = atual->prox_linha;
        atual->prox_linha = novo;
    }

    // Insere na lista de colunas
    if (matriz->colunas_cabeca[coluna] == NULL || matriz->colunas_cabeca[coluna]->linha > linha) {
        novo->prox_coluna = matriz->colunas_cabeca[coluna];
        matriz->colunas_cabeca[coluna] = novo;
    } else {
        No* atual = matriz->colunas_cabeca[coluna];
        while (atual->prox_coluna != NULL && atual->prox_coluna->linha < linha) {
            atual = atual->prox_coluna;
        }
        novo->prox_coluna = atual->prox_coluna;
        atual->prox_coluna = novo;
    }
}

// Função para remover um elemento da matriz
void remover(MatrizEsparsa* matriz, int linha, int coluna) {
    linha--; // Ajuste para indexação baseada em 0
    coluna--;

    // Verifica se a posição é válida
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("Posição inválida!\n");
        return;
    }

    // Remove da lista de linhas
    No* anterior = NULL;
    No* atual = matriz->linhas_cabeca[linha];
    while (atual != NULL && atual->coluna < coluna) {
        anterior = atual;
        atual = atual->prox_linha;
    }
    if (atual != NULL && atual->coluna == coluna) {
        if (anterior == NULL) {
            matriz->linhas_cabeca[linha] = atual->prox_linha;
        } else {
            anterior->prox_linha = atual->prox_linha;
        }
    }

    // Remove da lista de colunas
    anterior = NULL;
    atual = matriz->colunas_cabeca[coluna];
    while (atual != NULL && atual->linha < linha) {
        anterior = atual;
        atual = atual->prox_coluna;
    }
    if (atual != NULL && atual->linha == linha) {
        if (anterior == NULL) {
            matriz->colunas_cabeca[coluna] = atual->prox_coluna;
        } else {
            anterior->prox_coluna = atual->prox_coluna;
        }
        free(atual);
    }
}

// Função para buscar um elemento na matriz
int buscar(MatrizEsparsa* matriz, int linha, int coluna) {
    linha--; // Ajuste para indexação baseada em 0
    coluna--;

    // Verifica se a posição é válida
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        printf("Posição inválida!\n");
        return 0;
    }

    // Busca o elemento na lista de linhas
    No* atual = matriz->linhas_cabeca[linha];
    while (atual != NULL && atual->coluna < coluna) {
        atual = atual->prox_linha;
    }
    if (atual != NULL && atual->coluna == coluna) {
        return atual->valor;
    }
    return 0; // Retorna 0 se o elemento não for encontrado
}

// Função para imprimir a matriz
void imprimir(MatrizEsparsa* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%d ", buscar(matriz, i + 1, j + 1)); // Ajuste para indexação baseada em 1
        }
        printf("\n");
    }
}

// Função para somar duas matrizes esparsas
MatrizEsparsa* somar(MatrizEsparsa* matriz1, MatrizEsparsa* matriz2) {
    // Verifica se as matrizes têm o mesmo tamanho
    if (matriz1->linhas != matriz2->linhas || matriz1->colunas != matriz2->colunas) {
        printf("As matrizes devem ter o mesmo tamanho para serem somadas!\n");
        return NULL;
    }

    // Cria uma nova matriz para armazenar o resultado
    MatrizEsparsa* resultado = criar_matriz(matriz1->linhas, matriz1->colunas);

    // Soma os elementos correspondentes das duas matrizes
    for (int i = 1; i <= matriz1->linhas; i++) {
        for (int j = 1; j <= matriz1->colunas; j++) {
            int soma = buscar(matriz1, i, j) + buscar(matriz2, i, j);
            if (soma != 0) {
                inserir(resultado, i, j, soma);
            }
        }
    }

    return resultado;
}

// Função para calcular a soma de todos os elementos da matriz
int soma_interna(MatrizEsparsa* matriz) {
    int soma = 0;
    for (int i = 0; i < matriz->linhas; i++) {
        No* atual = matriz->linhas_cabeca[i];
        while (atual != NULL) {
            soma += atual->valor;
            atual = atual->prox_linha;
        }
    }
    return soma;
}

// Função para calcular a esparsidade da matriz
float calcular_esparsidade(MatrizEsparsa* matriz) {
    int elementos_nao_nulos = 0;
    for (int i = 0; i < matriz->linhas; i++) {
        No* atual = matriz->linhas_cabeca[i];
        while (atual != NULL) {
            elementos_nao_nulos++;
            atual = atual->prox_linha;
        }
    }
    int total_elementos = matriz->linhas * matriz->colunas;
    return (float)(total_elementos - elementos_nao_nulos) / total_elementos;
}

// Função para contar o número de elementos não nulos na matriz
int contar_elementos_nao_nulos(MatrizEsparsa* matriz) {
    int count = 0;
    for (int i = 0; i < matriz->linhas; i++) {
        No* atual = matriz->linhas_cabeca[i];
        while (atual != NULL) {
            count++;
            atual = atual->prox_linha;
        }
    }
    return count;
}

// Função para liberar a memória alocada para a matriz
void liberar_matriz(MatrizEsparsa* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        No* atual = matriz->linhas_cabeca[i];
        while (atual != NULL) {
            No* proximo = atual->prox_linha;
            free(atual);
            atual = proximo;
        }
    }
    free(matriz->linhas_cabeca);
    free(matriz->colunas_cabeca);
    free(matriz);
}