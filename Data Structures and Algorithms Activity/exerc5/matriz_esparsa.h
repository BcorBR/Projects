#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

// Estrutura para representar um nó da matriz esparsa
typedef struct No {
    int valor;         // Valor armazenado no nó
    int linha;         // Índice da linha do nó
    int coluna;        // Índice da coluna do nó
    struct No* prox_linha;  // Ponteiro para o próximo nó na mesma linha
    struct No* prox_coluna; // Ponteiro para o próximo nó na mesma coluna
} No;

// Estrutura para representar a matriz esparsa
typedef struct MatrizEsparsa {
    int linhas;        // Número total de linhas da matriz
    int colunas;       // Número total de colunas da matriz
    No** linhas_cabeca;  // Array de ponteiros para os nós cabeça de cada linha
    No** colunas_cabeca; // Array de ponteiros para os nós cabeça de cada coluna
} MatrizEsparsa;

// Função para criar uma nova matriz esparsa
MatrizEsparsa* criar_matriz(int linhas, int colunas);

// Função para inserir um elemento na matriz
void inserir(MatrizEsparsa* matriz, int linha, int coluna, int valor);

// Função para remover um elemento da matriz
void remover(MatrizEsparsa* matriz, int linha, int coluna);

// Função para buscar um elemento na matriz
int buscar(MatrizEsparsa* matriz, int linha, int coluna);

// Função para imprimir a matriz
void imprimir(MatrizEsparsa* matriz);

// Função para somar duas matrizes esparsas
MatrizEsparsa* somar(MatrizEsparsa* matriz1, MatrizEsparsa* matriz2);

// Função para calcular a soma de todos os elementos da matriz
int soma_interna(MatrizEsparsa* matriz);

// Função para calcular a esparsidade da matriz
float calcular_esparsidade(MatrizEsparsa* matriz);

// Função para liberar a memória alocada para a matriz
void liberar_matriz(MatrizEsparsa* matriz);

// Função para contar o número de elementos não nulos na matriz
int contar_elementos_nao_nulos(MatrizEsparsa* matriz);

#endif