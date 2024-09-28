#include <stdio.h>

/*
O(N^2)
na melhor das hipóteses, como o bubble: O(N)

O Insertion é um método super adaptável! Ele faz poucas trocas e comparações.
Ele se desempenha melhor se o problema for mais fácil (são três maneiras do problema ser mais fácil).
O insertion é em todas as situações!
Um vetor que já está ‘partially sorted’ (parcialmente ordenado) -> até uma parte está ordenado -> o bubble não é adaptável nesse caso.
Um vetor que já está ‘nearly sorted’ (quase ordenado) -> elemento já está quase próximo da sua posição final -> o bubble é adaptável nesse caso.
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

int main(){

    int array[10] = {5, 4, 8, 2, 4, 8, 2, 1, 0, 3};

    printArray(array, 10);
    insertion_sort(array, 10);
    printArray(array, 10);

    return 0;
};
