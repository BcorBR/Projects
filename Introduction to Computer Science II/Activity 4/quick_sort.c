#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d", arr[i]);
    puts("");
}

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quickSort(int *arr)


int main(){
    int arr[10] = {5, 2, 3,8, 5, 9, 3, 3, 0, 8};
    printArray(arr, 10);
    quickSort(arr, 10);
    printArray(arr, 10);


    return 0;
}