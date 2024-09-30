#include <stdio.h>
#include <stdlib.h>

// Time complexity = O(n + k), where n is the size of the original array \
   and k is the size of the frequency array
// Space Complexity = O(n + k)
// Really fast for small numbers
// Stable Algorithm
// 

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d", arr[i]);
    puts("");
}

void countingSort(int *arr, int size){
    // find the biggest number so we can make the array of frequencies
    int i;
    int biggest = arr[0];
    for (i = 1; i < size; i++){
        if (arr[i] > biggest)
            biggest = arr[i];
    }

    // index of this array is equal to number to be put in original array
    // it's value is equal to the amount of that number that are repeated in the array
    int *arrayIdx = (int *)malloc((biggest + 1)*sizeof(int));
    if (arrayIdx == NULL)
        printf("Error allocating arrayIdx\n");
    
    for (i = 0; i < biggest + 1; i++)
        arrayIdx[i] = 0;

    // curIdx is used to save index of current number in arrayIdx
    int curIdx = 0;
    
    for (i = 0; i < size; i++)
        arrayIdx[arr[i]]++; // index(number) : freq

    // go through arrayIDx starting in curIdx to save number index
    // add number of index if bigger than 0 e decrement by one
    // if equal to 0, next iteration
    i = 0;
    while (curIdx < biggest + 1){
        if (arrayIdx[curIdx] > 0){
            arr[i] = curIdx;
            arrayIdx[curIdx]--;
            i++;
        }
        else
            curIdx++;
    }
}



int main(){
    int arr[9] = {0, 3, 4, 2, 1, 2, 3, 1, 3};
    printArray(arr, 9);
    countingSort(arr, 9);
    printArray(arr, 9);

    return 0;
}