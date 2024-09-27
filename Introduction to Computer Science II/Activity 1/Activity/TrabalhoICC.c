#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    };
    puts("");
};

void swap(int *x, int *y){
    int tmp = *x;

    *x = *y;
    *y = tmp;
};

void bubble_sort(int arr[], int size){
    int i, j;
    bool swapped = false;
    size--;

    while (size > 0){
        j = size;
        swapped = false;
        for (i = 0; i < j; i++){
            printf("C %d %d\n", i, i+1);
            if (arr[i] > arr[i+1]){
                printf("T %d %d\n", i, i+1);
                swap(&arr[i], &arr[i+1]);
                swapped = true;
                size = i;
            }
        }
        if (swapped == false)
            break;
    }
};

void selection_sort(int arr[], int size){
    int i, j;
    int min_idx;

    for (j = 0; j < size - 1; j++){
        min_idx = j;
        for (i = j+1; i < size; i++){
            printf("C %d %d\n", min_idx, i);
            if (arr[i] < arr[min_idx]){
                min_idx = i;
            };
        };
        printf("T %d %d\n", j, min_idx);
        swap(&arr[min_idx], &arr[j]);
    };
};

int main(){
    char op[8] = {};
    int size;
    int size_while;
    int current_index = 0;

    scanf("%7s", op);
    scanf("%d", &size);

    int *array = (int *)malloc(sizeof(int) * size);
    if (array == NULL){
        puts("Erro ao alocar memoria");
        return 1;
    }
    
    size_while = size;

    while (size_while > 0){
        scanf("%d", &array[current_index]);
        current_index++;
        size_while--;
    }
    
    if (strcmp(op, "selecao") == 0){
            selection_sort(array, size);
            printArray(array, size);
        }
    else{
        bubble_sort(array, size);
        printArray(array, size);
    }

    return 0;  
};