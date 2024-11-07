#include <stdio.h>
#include "matriz_esparsa.h"

int main() {
    // Cria uma matriz esparsa 5x5
    MatrizEsparsa* matriz = criar_matriz(5, 5);
    int elementos_nao_nulos;

    // 1. Teste da função inserir()
    printf("1. Inserir():\n");
    inserir(matriz, 1, 1, 1);
    inserir(matriz, 2, 2, 2);
    inserir(matriz, 3, 3, 3);
    inserir(matriz, 4, 4, 4);
    inserir(matriz, 5, 5, 5);
    printf("Matriz após inserções:\n");
    imprimir(matriz);

    // Conta e exibe o número de elementos não nulos e a esparsidade
    elementos_nao_nulos = contar_elementos_nao_nulos(matriz);
    printf("\nElementos não nulos na matriz original: %d\n", elementos_nao_nulos);
    printf("Esparsidade da matriz original: %.2f\n", calcular_esparsidade(matriz));

    // 2. Teste da função inserir() com valor zero (deve remover o elemento)
    printf("\n2. Inserir() com valor zero (deve remover):\n");
    inserir(matriz, 3, 3, 0);
    printf("Matriz após remover elemento (3,3):\n");
    imprimir(matriz);

    // 3. Teste da função inserir() para atualizar um valor existente
    printf("\n3. Inserir() para atualizar um valor:\n");
    inserir(matriz, 2, 2, 10);
    printf("Matriz após atualizar elemento (2,2) para 10:\n");
    imprimir(matriz);

    // 4. Teste da função remover()
    printf("\n4. Remover():\n");
    remover(matriz, 4, 4);
    printf("Matriz após remover elemento (4,4):\n");
    imprimir(matriz);

    // 5. Teste da função buscar()
    printf("\n5.Buscar():\n");
    printf("Valor na posição (2,2): %d\n", buscar(matriz, 2, 2));
    printf("Valor na posição (3,3) (deve ser 0): %d\n", buscar(matriz, 3, 3));

    // 6. Teste da função soma_interna()
    printf("\n6. SomaInterna():\n");
    printf("Soma interna da matriz: %d\n", soma_interna(matriz));

    // 7. Teste da função somar()
    printf("\n7. Somar():\n");
    // Cria uma segunda matriz para somar com a primeira
    MatrizEsparsa* matriz2 = criar_matriz(5, 5);
    inserir(matriz2, 1, 1, 5);
    inserir(matriz2, 2, 2, 4);
    inserir(matriz2, 3, 3, 3);
    inserir(matriz2, 4, 4, 2);
    inserir(matriz2, 5, 5, 1);

    printf("Matriz 2:\n");
    imprimir(matriz2);

    // Realiza a soma das duas matrizes
    MatrizEsparsa* soma = somar(matriz, matriz2);
    printf("Resultado da soma das matrizes:\n");
    imprimir(soma);

    // Libera a memória alocada para todas as matrizes
    liberar_matriz(matriz);
    liberar_matriz(matriz2);
    liberar_matriz(soma);

    return 0;
}