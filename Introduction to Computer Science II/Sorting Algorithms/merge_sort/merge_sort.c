#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  O merge sort é O(nlogn) e, caso já ordenado, O(n)
    sua disvantagem é o uso de memóri, O(n)
    A divide and conquer algorithm is a strategy of solving a large problem by
    breaking the problem into smaller sub-problems
    solving the sub-problems, and
    combining them to get the desired output.
    To use the divide and conquer algorithm, recursion is used.

    Algorítmo estável*/


void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    puts("");
}

void merge(int arr[], int arr1[], int arr2[], int size1, int size2){
    int idx0 = 0;
    int idx1 = 0;
    int idx2 = 0;

    // compare numbers and paste in original array
    while (idx1 != size1 && idx2 != size2){
        if (arr1[idx1] <= arr2[idx2]){
            arr[idx0] = arr1[idx1];
            idx0++;
            idx1++;
        }
        else if (arr2[idx2] < arr1[idx1]){
            arr[idx0] = arr2[idx2];
            idx0++;
            idx2++;
        }
    }

    // in case one of the arrays has ended, paste the remaining numbers of the remaining array in the original array
    if (idx1 == size1){
        while (idx2 != size2){
            arr[idx0] = arr2[idx2];
            idx0++;
            idx2++;
        }
    }
    else if (idx2 == size2){
        while (idx1 != size1){
            arr[idx0] = arr1[idx1];
            idx0++;
            idx1++;
        }
    }
}


void mergeSort(int arr[], int size){
    if (size <= 1)
        return;
    
    int i;   
    int size1;
    int size2;

    // distributing right size of arrays
    if (size % 2 != 0){
        size1 = size/2;
        size2 = size1 + 1;
    }
    else{
        size1 = size/2;
        size2 = size1;
    }


    int *arr1 = (int *)malloc(size1 * sizeof(int));
    if (arr1 == NULL){
        printf("Erro ao alocar array 1\n");
        exit(EXIT_FAILURE);
    }

    int *arr2 = (int *)malloc(size2 * sizeof(int));
    if (arr2 == NULL){
        printf("Erro ao alocar array 2\n");
        exit(EXIT_FAILURE);
    }

    // putting values into divided arrays
    for (i = 0; i < size; i++){
        if (i < size1)
            arr1[i] = arr[i];
        else if (i < size){
            arr2[i - size1] = arr[i];
        }
    }

    mergeSort(arr1, size1);
    mergeSort(arr2, size2);
    
    merge(arr, arr1, arr2, size1, size2);
    return;
}



int main(){
    int array[9] = {0, 3, 0, 3, 0, 2, 4, 2, 3};

    printArray(array, 9);
    mergeSort(array, 9);
    printArray(array, 9);

    return 0;
}