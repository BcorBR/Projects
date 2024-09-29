#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Shell Sort
// TIme complexity depends on implementation
// In this case, the gap number will be found with the formula g = (3^k - 1)/2
// Time complexity will therefore be O(n^(3/2))
// Space Complexity is O(1)
// It's not adaptable as it will always scan through all the gaps

// g = gaps
// k = number of sort
// n = size of array
// g = (3^k - 1)/2
// gap will be: 1, 4, 13, 40, 121...
// gap will never be greater than n/3

// the last gap must be one and, for better results, gaps should be primes

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void shellSort(int *arr, int size){
    // k = log3(2n + 3) - 1
    int k = (log(2*size+3)/log(3)) - 1;
    int i = 0, j = 0, limit = 0;
    int g = (pow(3, k) - 1)/ 2;

    while (g > 0){
        for (i = 0; i + g < size; i++){ 
            if (arr[i+g] < arr[i]){
                swap(&arr[i+g], &arr[i]);

                // if swapped is made, scan wil be made backwards until end of array or until \
                   non-swappable pair is found
                for (int j = i - g; j >= 0; j -= g){
                    if (arr[j+g] < arr[j])
                        swap(&arr[j+g], &arr[j]);
                    else
                        break;
                }
            }
        }
        g = (g-1)/3;
    }
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d", arr[i]);
    puts("");
    
}

int main(){
    int arr[12] = {4, 3, 5, 8, 1, 2, 6, 4, 3, 4, 7, 4};
    shellSort(arr, 12);
    printArray(arr, 12);

    return 0;

}