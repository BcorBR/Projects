#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        heapSort(arr1, Amount);
        for (int i = 0; i < Amount2; i++){
            if (interpolSearch(0, Amount - 1, arr2[i], arr1))
                printf("1\n");
            else
                printf("0\n");
        }
    }
    else{
        for (int i = 0; i < Amount2; i++){
            if (LinSearch(arr2[i], arr1, Amount - 1))
                printf("1\n");
            else
                printf("0\n");
        }
    }


    return 0;
}