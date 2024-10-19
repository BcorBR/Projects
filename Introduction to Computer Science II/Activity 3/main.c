#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void shell(int v[], int n, int *shellCompare, int *shellCopy) {
    int gap = 1;

    // n = size
    // gap = 2^k - 1
    while(gap <= n)
        gap *= 2;
    
    gap = gap / 2 - 1;
    
    while(gap > 0) {
        for (int i = gap; i < n; i++){
        
            (*shellCompare)++;

            int x = v[i];
            int j = i - gap;

            while(j >= 0) {
                (*shellCompare)++;

                if (v[j] > x){
                    (*shellCopy)++;

                    v[j + gap] = v[j];
                    j -= gap;
                }
                else
                    break;
            }
            
            (*shellCopy)++;
            v[j + gap] = x;

        }
    gap /= 2;
    }
}

void quick(int v[], int f, int l, int *quickCompare, int *quickCopy) {
    if (f >= l) 
        return;
    
    // f = first
    // l = last

    // index pivot   

    int m = (l + f)/2;
    (*quickCompare)++;
    int pivot = v[m];

    //index on pivot's left
    int i = f;
    // index on pivot's right
    int j = l;

    while(1) {
        // if element on left smaller than pivot, go to the next one
        while(1) {
            (*quickCompare)++;
            if (v[i] < pivot)
                i++;
            else
                break;
        }

        // if element on right bigger than pivot, go to the next one
        while(1){
            (*quickCompare)++;
            if (v[j] > pivot)
                j--;
            else
                break;
        }

        if (i >= j) 
            break;

        (*quickCopy) += 3;
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        i++;
        j--;
    }


    quick(v, f, j, quickCompare, quickCopy);
    quick(v, j+1, l, quickCompare, quickCopy);

}


int main(){
    int shellCompare = 0, shellCopy = 0, quickCompare = 0, quickCopy = 0;
    

    //printf("%p, %p, %p, %p", shellCompare, shellCopy, quickCompare, quickCopy);
    // reads the N number of elements in an array 
    // then reads N numbers of elements in array
    int Amount;


    // read the N number
    scanf("%d", &Amount);

    int *arr = (int *)malloc(Amount * sizeof(int));
    if (arr == NULL){
        printf("Error allocating arrQ\n");
        exit(EXIT_FAILURE);
    }


    int i;
    // read the array
    for (i = 0; i < Amount; i++){
        scanf("%d", &arr[i]);
    }
    
    int j;
    // make subvectors to be read as arguments
    for (i = 0; i < Amount; i++){
        // allocate right size of subvectors in each iteration
        int *arrS = (int *)malloc((i+1) * sizeof(int));
        int *arrQ = (int *)malloc((i+1) * sizeof(int));

        // associate values to subvector's indexes
        for (j = 0; j < i + 1; j++){
            arrS[j] = arr[j];
            arrQ[j] = arr[j];
        }

        shell(arrS, i+1, &shellCompare, &shellCopy);
        quick(arrQ, 0, (i+1) - 1, &quickCompare, &quickCopy);

        // print outputs
        if ((shellCompare + shellCopy) < (quickCompare + quickCopy))
            printf("S");
        else if ((shellCompare + shellCopy) > (quickCompare + quickCopy))
            printf("Q");
        else
            printf("-");

        // reset counters for next iteration
        shellCompare = 0;
        shellCopy = 0;
        quickCompare = 0;
        quickCopy = 0;

        free(arrS);
        free(arrQ);
    }

    return 0;
}