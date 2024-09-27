#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void updateSwap(int *mergeSwap){
    (*mergeSwap)++;
}

void updateCompare(int *mergeCompare){
    (*mergeCompare)++;
}

void insertion_sort(int arr[], int size){
    int i, j;
    int main;
    int swaps = 0;
    int compare = 0;

    for (i = 1; i < size; i++){
        main = arr[i];
        swaps++;
        for (j = i-1; j >= 0; j--){
            compare++;

            if (arr[j] > main){
                arr[j+1] = arr[j];
                swaps++;
            }
            else{
                break;
            }
        }
        arr[j+1] = main;
        swaps++;
    }
    // METHOD, SIZE, SWAPS, COMPARISONS
    printf("I %d %d %d\n", size, swaps, compare);
};


void merge(int arr[], int arr1[], int arr2[], int size1, int size2, int *mergeSwap, int *mergeCompare){
    int idx0 = 0;
    int idx1 = 0;
    int idx2 = 0;

    // compare numbers and paste in original array
    while (idx1 != size1 && idx2 != size2){
        updateCompare(mergeCompare);
        
        if (arr1[idx1] <= arr2[idx2]){
            updateSwap(mergeSwap);
            arr[idx0] = arr1[idx1];
            idx0++;
            idx1++;
        }
        else if (arr2[idx2] < arr1[idx1]){
            updateSwap(mergeSwap);
            arr[idx0] = arr2[idx2];
            idx0++;
            idx2++;
        }
    }

    // in case one of the arrays has ended, paste the remaining numbers of the remaining array in the original array
    if (idx1 == size1){
        while (idx2 != size2){
            updateSwap(mergeSwap);
            arr[idx0] = arr2[idx2];
            idx0++;
            idx2++;
        }
    }
    else if (idx2 == size2){
        while (idx1 != size1){
            updateSwap(mergeSwap);
            arr[idx0] = arr1[idx1];
            idx0++;
            idx1++;
        }
    }
}


void mergeSort(int arr[], int size, int firstCall, int *mergeSwap, int *mergeCompare){
    if (size <= 1)
        return;
    
    int i;   
    int size1;
    int size2;

    // distributing right size of arrays
    if (size % 2 != 0){
        size2 = size/2;
        size1 = size2 + 1;
    }
    else{
        size2 = size/2;
        size1 = size2;
    }


    int *arr1 = (int *)malloc(size1 * sizeof(int));
    if (arr1 == NULL){
        printf("Error allocating array 1\n");
        exit(EXIT_FAILURE);
    }

    int *arr2 = (int *)malloc(size2 * sizeof(int));
    if (arr2 == NULL){
        printf("Error allocating array 2\n");
        exit(EXIT_FAILURE);
    }

    // putting values into divided arrays
    for (i = 0; i < size; i++){
        updateSwap(mergeSwap);
        if (i < size1)
            arr1[i] = arr[i];
        else if (i < size){
            arr2[i - size1] = arr[i];
        }
    }

    mergeSort(arr1, size1, 0, mergeSwap, mergeCompare);
    mergeSort(arr2, size2, 0, mergeSwap, mergeCompare);
    
    merge(arr, arr1, arr2, size1, size2, mergeSwap, mergeCompare);

    // METHOD, SIZE, SWAPS, COMPARISONS
    if (firstCall == 1)
        printf("M %d %d %d\n", size, *mergeSwap,*mergeCompare);

    return;
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    puts("");
}

int main(){
    int Amount; // Amount of arrays to be analyzed
    int maxSize = 1;
    int i, j;
    
    // output as M(method) N(size of array) T(number of attributions) C(number of comparisons)
    scanf("%d", &Amount);

    // Number of elements in each of the arrays
    int *sizes = (int *)malloc(Amount * sizeof(int));
    if (sizes == NULL){
        printf("Error alocating sizes array\n");
        exit(EXIT_FAILURE);
    }

    // Take the array with the biggest size and make one array with this biggest size
    // analysis can be limited to the number of elements of the current array being analyzed
    for (i = 0; i < Amount; i++){
        scanf("%d", &sizes[i]);
        if (sizes[i] > maxSize)
            maxSize = sizes[i];
    }

    // one array for insertion and other for merge
    int *array = (int *)malloc(maxSize * sizeof(int));
    if (array == NULL){
        printf("Error allocating Array 1\n");
        exit(EXIT_FAILURE);
    }
    int *array2 = (int *)malloc(maxSize * sizeof(int));
    if (array2 == NULL){
        printf("Error allocating Array 2\n");
        exit(EXIT_FAILURE);
    }

    int mergeSwap = 0;
    int mergeCompare = 0;

    // i for each array
    // j for each size of arrays
    for (i = 0; i < Amount; i++){
        for (j = 0; j < sizes[i]; j++){
            scanf("%d", &array[j]);
            array2[j] = array[j];
        }

        insertion_sort(array, sizes[i]);
        mergeSort(array2, sizes[i], 1, &mergeSwap, &mergeCompare);

        mergeSwap = 0;
        mergeCompare = 0;      
    }
    return 0;
}