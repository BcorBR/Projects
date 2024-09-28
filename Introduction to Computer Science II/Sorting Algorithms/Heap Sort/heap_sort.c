#include <stdlib.h>
#include <stdio.h>

// Time complexity: O(nlogn)
// Space complexity: O(1) for iterative implementation and O(logn) for recursive implementation
// Typically not stable but can be made stable depending of implementation

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp; 
}

void heapSort(int *arr, int size){
    int finIdx = size - 1;
    int i;
    
    while (finIdx != 0){
        for (i = finIdx; i > 0; i--){
            if (arr[i] > arr[(i - 1) / 2])
                swap(&arr[i], &arr[(i - 1) / 2]);
        }
        swap(arr, &arr[finIdx]);
        finIdx -= 1;
    }
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d", arr[i]);
    puts("");
}

int main(){
    int arr[9] = {6, 2, 1, 8, 4, 6, 2, 2, 1};
    printArray(arr, 9);

    heapSort(arr, 9);
    printArray(arr, 9);

    return 0;
}