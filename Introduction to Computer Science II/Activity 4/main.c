#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int interpolSearch(int first, int last, int val, int *arr){
    int position = first + 1;
    while ( val > arr[first] && val <= arr[last]){
        position = first + ((last - first)/(arr[last] - arr[first])) * (val - arr[first]);

        if (val > arr[position])
            first = position + 1;
        else if (val < arr[position])
            last = position - 1;
        else
            return 1;
    }
    if (arr[first] == val)
        return 1;
    return 0;
}

int binSearch(int *arr, int val, int size){
    int left = 0, mid;
    int right = size - 1;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (val > arr[mid])
            left = mid + 1;

        else if (val < arr[mid])
            right = mid - 1;
    
        else
            return 1;
    }
    return 0;
}

int LinSearch(int val, int *arr, int last){
    for (int i = 0; i < last; i++){
        if (arr[i] == val)
            return 1;
    }
    return 0;
}

int main(int argv[]){
    int Amount;
    int Amount2;

    scanf("%d", &Amount);
    // array of numbers
    int *arr1 = (int *)malloc(sizeof(int) * Amount);
    for (int i = 0; i < Amount; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &Amount2);
    // array of numbers to be searched
    int *arr2 = (int *)malloc(sizeof(int) * Amount2);
    for  (int i = 0; i < Amount2; i++)
        scanf("%d", &arr2[i]);

    // if number of searches  is bigger than log2(n), sort it
    if (Amount2 > log(Amount)/log(2)){
        quickSort(arr1, 0, Amount - 1);
        for (int i = 0; i < Amount2; i++){
            if (binSearch(arr1, arr2[i], Amount))
                printf("1\n");
            else
                printf("0\n");
        }
    }
    else{
        for (int i = 0; i < Amount2; i++){
            if (LinSearch(arr2[i], arr1, Amount))
                printf("1\n");
            else
                printf("0\n");
        }
    }


    return 0;
}