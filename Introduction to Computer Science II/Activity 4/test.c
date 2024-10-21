#include <stdio.h>

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

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int arr[16] = {-1, 2, 7, 0, 0, 0, 2, 5, 7, 1, -6, -5, -9, 10, 34, 65};

    printArray(arr, 16);
    heapSort(arr, 16);
    printArray(arr, 16);

    for (int i = -9; i < 66; i++){
        if (interpolSearch(0, 15, i, arr))
            printf("number %d found\n\n", i);
        else
            printf("number %d not found\n\n", i);
    }
    
    // -9 -6 -5 -1 0 0 0 1 2 2 5 7 7 10 34 65

    return 0;
}