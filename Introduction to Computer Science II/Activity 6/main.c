#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 100
#define TAMANHO_SEQUENCIA 1024
// Lucas Daniel Volpiano Figueiredo 14778244
// Ana Rita Marega Gonçalves 15746365
// Gabriel de Oliveira Merenciano 15746705
// Bruno Corrêa Barreto 15443896


char *reorganizar_sequencias(char matriz_sequencias[TAMANHO_MAXIMO][TAMANHO_SEQUENCIA], 
                           char sequencia_nova[TAMANHO_SEQUENCIA], int quantidade) {
    static char sequencia_final[TAMANHO_SEQUENCIA];
    
    if (matriz_sequencias[0][0] == '\0') {
        strcpy(matriz_sequencias[0], sequencia_nova);
        strcpy(sequencia_final, matriz_sequencias[0]);
    } 
    else {
        int indice = 0;
        char sequencia_temporaria[TAMANHO_SEQUENCIA];
        strcpy(sequencia_temporaria, matriz_sequencias[indice]);
        strcpy(matriz_sequencias[indice], sequencia_nova);
        indice++;

        while (indice < quantidade) {
            if (matriz_sequencias[indice][0] == '\0') {
                strcpy(matriz_sequencias[indice], sequencia_temporaria);
                strcpy(sequencia_final, matriz_sequencias[indice]);
                break;
            } 
            else {
                char sequencia_auxiliar[TAMANHO_SEQUENCIA];
                strcpy(sequencia_auxiliar, matriz_sequencias[indice]);
                strcpy(matriz_sequencias[indice], sequencia_temporaria);
                strcpy(sequencia_temporaria, sequencia_auxiliar);
                strcpy(sequencia_final, matriz_sequencias[indice]);
                indice++;
            }
        }
    }
    return sequencia_final;
}

char *combinar_sequencias(int tamanho_sobreposicao, 
                         char matriz_sequencias[TAMANHO_MAXIMO][TAMANHO_SEQUENCIA], 
                         int indice_seq1, int indice_seq2, int posicao_sobreposicao, 
                         int quantidade) {
    static char sequencia_combinada[TAMANHO_SEQUENCIA];

    if (tamanho_sobreposicao == 0) {
        strcpy(sequencia_combinada, matriz_sequencias[indice_seq1]);
        strcat(sequencia_combinada, matriz_sequencias[indice_seq2]);
    } 
    else if (posicao_sobreposicao == -1) {
        strcpy(sequencia_combinada, matriz_sequencias[indice_seq1]);
    } 
    else {
        strcpy(sequencia_combinada, matriz_sequencias[indice_seq1]);
        strcpy(&sequencia_combinada[posicao_sobreposicao], matriz_sequencias[indice_seq2]);
    }
    
    matriz_sequencias[indice_seq1][0] = '\0';
    matriz_sequencias[indice_seq2][0] = '\0';

    return reorganizar_sequencias(matriz_sequencias, sequencia_combinada, quantidade);
}

char *processar_modificacoes(char matriz_sequencias[TAMANHO_MAXIMO][TAMANHO_SEQUENCIA], 
                           int quantidade) {
    int i, j, maior_sobreposicao = -1, sobreposicao_atual = 0;
    int sequencia_primeira = 0, sequencia_segunda = 0;
    int posicao_temporaria = 0, posicao_final = 0;

    for (i = 0; i < quantidade; i++) {
        if (matriz_sequencias[i][0] == '\0')
            continue;

        for (j = 0; j < quantidade; j++) {
            if (matriz_sequencias[j][0] == '\0' || i == j)
                continue;

            sobreposicao_atual = 0;
            char *resultado_busca = strstr(matriz_sequencias[i], matriz_sequencias[j]);
            if (resultado_busca != NULL) {
                sobreposicao_atual = strlen(matriz_sequencias[j]);
                posicao_temporaria = -1;
            } 
            else {
                int indice_comparacao;
                int tamanho_primeira = strlen(matriz_sequencias[i]);
                int tamanho_segunda = strlen(matriz_sequencias[j]);
                
                indice_comparacao = (tamanho_primeira >= tamanho_segunda) ? 
                                   (tamanho_primeira - tamanho_segunda) : 0;

                while (indice_comparacao < tamanho_primeira) {
                    sobreposicao_atual = strncmp(&matriz_sequencias[i][indice_comparacao], 
                                               matriz_sequencias[j], 
                                               (tamanho_primeira - indice_comparacao));
                    posicao_temporaria = indice_comparacao;
                    if (sobreposicao_atual == 0) {
                        sobreposicao_atual = strlen(&matriz_sequencias[i][indice_comparacao]);
                        break;
                    } 
                    else {
                        sobreposicao_atual = 0;
                    }
                    indice_comparacao++;
                }
            }

            if (sobreposicao_atual > maior_sobreposicao) {
                maior_sobreposicao = sobreposicao_atual;
                sequencia_primeira = i;
                sequencia_segunda = j;
                posicao_final = posicao_temporaria;
            }
        }
    }

    return combinar_sequencias(maior_sobreposicao, matriz_sequencias, 
                             sequencia_primeira, sequencia_segunda, 
                             posicao_final, quantidade);
}

int main() {
    int quantidade_sequencias;
    char matriz_sequencias[TAMANHO_MAXIMO][TAMANHO_SEQUENCIA];
    char sequencia_entrada[TAMANHO_SEQUENCIA];
    char *sequencia_final;

    scanf("%d", &quantidade_sequencias);

    for (int i = 0; i < quantidade_sequencias; i++) {
        scanf(" %s", sequencia_entrada);
        strcpy(matriz_sequencias[i], sequencia_entrada);
    }

    for (int j = 0; j < quantidade_sequencias - 1; j++) {
        sequencia_final = processar_modificacoes(matriz_sequencias, quantidade_sequencias);
    }

    printf("%s\n", sequencia_final);

    return 0;
}