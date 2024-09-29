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

void quickSort(int *arr, int size){
    // recursion filter
    if (size <= 1)
        return;
    
    int pv = size - 1;
    int pointL = 0, pointR = pv - 1;

    printArray(arr, size);
    // place elements smaller than pivot in it's future left side
    while (pointR > pointL){
        printArray(arr, size);
        while (arr[pointL] <= arr[pv])
            pointL++;
        while (arr[pointR] >= arr[pv])
            pointR--;
        if (arr[pointL] > arr[pv] && arr[pointR] < arr[pv])
            swap(&arr[pointL], &arr[pointR]);
    }
    // place pivot in correct position of array
    swap(&arr[pointL], &arr[pv]);
    printArray(arr, size);

    

    quickSort(arr, pv);
    quickSort(&arr[pv+1], size - pv - 1);
}


int main(){
    int arr[10] = {5, 2, 3,8, 5, 9, 3, 3, 0, 8};
    printArray(arr, 10);
    quickSort(arr, 10);
    printArray(arr, 10);


    return 0;
}