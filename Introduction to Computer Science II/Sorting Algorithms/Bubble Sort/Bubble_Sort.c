#include <stdbool.h>
#include <stdio.h>

/*
Time Complexity: O(N2)
Auxiliary Space: O(1)

Advantages of Bubble Sort:
Bubble sort is easy to understand and implement.
It does not require any additional memory space.
It is a stable sorting algorithm, meaning that elements with the
  same key value maintain their relative order in the sorted output.

Disadvantages of Bubble Sort:
Bubble sort has a time complexity of O(N2) which makes it
  very slow for large data sets.
Bubble sort is a comparison-based sorting algorithm,
  which means that it requires a comparison operator to determine the
    relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.

� considerado um algor�timo adapt�vel

Adaptive Sorting Algorithms:
The sorting algorithms in which the order of elements affects
  the time complexity of the sorting algorithm is known as an adaptive sorting algorithm.
In adaptive sorting, if the data is already sorted, the algorithm will not reorder the elements.
  As a result, it reduces the number of iterations and improves execution speed.

Advantages of Adaptive Sorting Algorithms:
When the data is already sorted, it consumes less time.
They generally load faster.
Improved execution speed.
*/

/* Em vetores j� ordenados, tem complexidade O(n), por ser adapt�vel, neste caso se adapta a vetores j� bem ordenados.

   Dado um vetor que est� quase ordenado, podemos usar Bubble com sentinela
   -> Ele faz o primeiro loop e marca onde foi feita a �ltima troca de valores.
   Ao inv�s de decrementar 1 no loop, ele vai at� a posi��o que fez a �ltima troca,
   pois significa que dali em diante n�o precisa mais de trocas.
*/

void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    };
    puts("");
};

void swap(int *x, int *y){
    int tmp = *x;

    *x = *y;
    *y = tmp;
};

void bubble_sort(int arr[], int size){
    int i, j;
    bool swapped = false;
    size--;

    while (size > 0){
      j = size;
      swapped = false;
      for (i = 0; i < j; i++){
          if (arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            swapped = true;
            size = i;
          }
      }
      if (swapped == false)
          break;
    }
}

int main(){
    int array[4] = {3, 6, 5, 2};

    printArray(array, 4);
    bubble_sort(array, 4);
    printArray(array, 4);

    return 0;
};
