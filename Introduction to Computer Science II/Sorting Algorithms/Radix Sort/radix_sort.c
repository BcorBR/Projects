#include <stdlib.h>
#include <stdio.h>


int getMax(int *arr, int size){
    int i;
    int max = arr[0];

    for (i = 1; i < size; i ++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void decSort(int *arr, int size, int place){
    int i;

    int *freq = (int *)malloc(10 * sizeof(int));
    if (freq == NULL){
        printf("Error allocating freq array\n");
        exit(EXIT_FAILURE);
    }

    // allocates 0 for each index of frequency array that might be incremented afterwards
    for (i = 0; i < 10; i++)
        freq[i] = 0;

    // adds 1 to frequency of each digit found
    for (i = 0; i < size; i++)
        freq[(arr[i] / place) % 10]++;

    // adds past digit freq to current freq so it becomes a precise index number
    for (i = 1; i < 10; i++)
        freq[i] += freq[i-1];

    // new array is made isolated to latter be copied into original array
    int *tempArray = (int *)malloc(size * sizeof(int));
    if (tempArray == NULL){
        printf("Error allocating tempArray\n");
        exit(EXIT_FAILURE);
    }

    // build temp array from end to beginning so it maintains stability
    for (i = size-1; i >= 0; i--){
        tempArray[freq[(arr[i] / place) % 10] - 1] = arr[i];
        freq[(arr[i] / place) % 10]--;  
    }

    // copy tempArray into array
    for (i = 0; i < size; i++)
        arr[i] = tempArray[i];

    free(freq);
    free(tempArray);

}

void radixSort(int *arr, int size){
    int max = getMax(arr, size);
    // decimal place
    int place;

    // separate iteration for each decimal and call sort function
    // if (max / currentDecimal) < 1 break, as decimal place limit has been reached
    for (place = 1; max / place > 0 ; place*=10)
        decSort(arr, size, place);

}


void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}


int main(){
    int arr[5] = {22, 556, 123, 11, 33};
    printArray(arr, 5);
    radixSort(arr, 5);
    printArray(arr, 5);


    return 0;
}