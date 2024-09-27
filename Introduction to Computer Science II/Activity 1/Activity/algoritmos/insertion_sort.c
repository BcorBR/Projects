#include <stdio.h>

/*
O(N^2)
na melhor das hip�teses, como o bubble: O(N)

O Insertion � um m�todo super adapt�vel! Ele faz poucas trocas e compara��es.
Ele se desempenha melhor se o problema for mais f�cil (s�o tr�s maneiras do problema ser mais f�cil).
O insertion � em todas as situa��es!
Um vetor que j� est� �partially sorted� (parcialmente ordenado) -> at� uma parte est� ordenado -> o bubble n�o � adapt�vel nesse caso.
Um vetor que j� est� �nearly sorted� (quase ordenado) -> elemento j� est� quase pr�ximo da sua posi��o final -> o bubble � adapt�vel nesse caso.
*/
void insertion_sort(int arr[], int size){
    int i, j;
    int main;

    for (i = 1; i < size; i++){
        main = arr[i];
        for (j = i-1; j >= 0; j--){
            if (arr[j] > main){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = main;
    }
};

void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    puts("");
};