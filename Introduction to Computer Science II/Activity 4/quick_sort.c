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

void quickSort(int *arr, int left, int right) {
    if (left >= right) 
        return;
    
    int mid = (right + left)/2;
    int pivot = arr[mid];
    int i = left;
    int j = right;
    while(1) {
        while(arr[i] < pivot) 
            i++;
        while(arr[j] > pivot) 
            j--;
        if (i >= j) 
            break;
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
    quickSort(arr, left, j);
    quickSort(arr, j+1, right);
}


int main(){
    int arr[10] = {5, 2, 3,8, 5, 9, 3, 3, 0, 8};
    printArray(arr, 10);
    quickSort(arr, 0, 9);
    printArray(arr, 10);


    return 0;
}