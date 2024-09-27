#include <stdio.h>
#include <stdbool.h>
#include "selection_sort.h"

/* Time Complexity: The time complexity of Selection Sort is O(N2)
   Auxiliary Space: O(1)

   � inst�vel
   N�o funciona bem com dados grandes
*/

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
};

void selection_sort(int arr[], int size){
    int i, j;
    int min_idx;

    for (j = 0; j < size - 1; j++){
        min_idx = j;
        for (i = j; i < size; i++){
            if (arr[i] < arr[min_idx]){
                min_idx = i;
            };
        };
        if (arr[min_idx] != arr[j]){
            swap(&arr[min_idx], &arr[j]);
        };
    };
};