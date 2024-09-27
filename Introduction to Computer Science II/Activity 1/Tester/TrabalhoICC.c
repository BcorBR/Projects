#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "comparison.h"

void swap(int *x, int *y){
    int tmp = *x;

    *x = *y;
    *y = tmp;
};

void printArray_nor(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    };
    puts("");
};

void bubble_sort_nor(int arr[], int size){
    int i, j;
    bool swapped = false;

    for (j = size - 1; j > 0; j--){
        swapped = false;
        for (i = 0; i < j; i++){
            printf("C %d %d\n", i, i+1);
            if (arr[i] > arr[i+1]){
                printf("T %d %d\n", i, i+1);
                swap(&arr[i], &arr[i+1]);
                swapped = true;
            }
        };
        if (swapped == false){
            break;
        };
        };
    printArray_nor(arr, size);
};

void selection_sort_nor(int arr[], int size){
    int i, j;
    int min_idx;

    for (j = 0; j < size - 1; j++){
        min_idx = j;
        for (i = j+1; i < size; i++){
            printf("C %d %d\n", min_idx, i);
            if (arr[i] < arr[min_idx]){
                min_idx = i;
            };
        };
        printf("T %d %d\n", j, min_idx);
        swap(&arr[min_idx], &arr[j]);
    };
    printArray_nor(arr, size);
};


void printArray(int arr[], int size, FILE *f){
    int i;

    for (i = 0; i < size; i++){
        fprintf(f, "%d ", arr[i]);
    };
    fputs("", f);
};


void bubble_sort(int arr[], int size, FILE *f){
    int i, j;
    bool swapped = false;
    int perma_size = size;
    size--;

    while (size > 0){
        j = size;
        swapped = false;
        for (i = 0; i < j; i++){
            fprintf(f, "C %d %d\n", i, i+1);
            if (arr[i] > arr[i+1]){
                fprintf(f, "T %d %d\n", i, i+1);
                swap(&arr[i], &arr[i+1]);
                swapped = true;
                size = i;
            }
        };
        if (swapped == false){
            break;
        };
    };
    printArray(arr, perma_size, f);
};

void selection_sort(int arr[], int size, FILE *f){
    int i, j;
    int min_idx;

    for (j = 0; j < size - 1; j++){
        min_idx = j;
        for (i = j+1; i < size; i++){
            fprintf(f, "C %d %d\n", min_idx, i);
            if (arr[i] < arr[min_idx]){
                min_idx = i;
            };
        };
        fprintf(f, "T %d %d\n", j, min_idx);
        swap(&arr[min_idx], &arr[j]);
    };
    printArray(arr, size, f);
};

int main(){
    char op[8];
    int size;
    char in_path[50];  
    
    // managing files
    DIR *directory;
    struct dirent *entry;

    directory = opendir("input");
    if (directory == NULL){
        printf("Error opening directory\n");
        return 1;
    }

    while ((entry = readdir(directory)) != NULL){
        if (entry->d_type == DT_REG){
            sprintf(in_path, "input/%s", entry->d_name);
            
            FILE *fp;
            fp = fopen(in_path, "r");
            if (fp == NULL){
                printf("Error opening %s file, NULL pointer\n", entry->d_name);  
                return 1;
            }
            
            // obtaining input from file
            int ch;
            int i = 0;
            int data = 0;

            fgets(op, 8, fp);
            fscanf(fp, "%d", &size);

            int *array = (int *)malloc(sizeof(int) * size);
            if (array == NULL){
                printf("Error allocating memory: %s\n", errno);
                return 1;
            }
            
            i = 0;

            while (i < size){
                fscanf(fp, "%d", &array[i]);
                i++;
            }     
            
            
            // producion of output
            char *format = strrchr(entry->d_name, '.');
            if (format == NULL){
                printf("Error, output's path string could not be manipulated");
                return 1;
            }
            
            strcpy(format, ".out");
            sprintf(in_path, "output_personal/%s", entry->d_name);
            
            fp = fopen(in_path, "w");
            if (fp == NULL){
                printf("Error, pointer to %s file is NULL", in_path);
                return 1;
            }

            if (!(strcmp(op, "selecao")))
                selection_sort(array, size, fp);
            else
                bubble_sort(array, size, fp);
            
            free(array);

            if (fclose(fp) != 0){
                printf("Error closing file: %d\n", errno);
                return 1;
            }
        };              
    }       

    if (closedir(directory) == -1){
        printf("Error closing directory\n");
        return 1;
    }
    free(directory);
    free(entry);

    // comparing the files
    compare();

    return 0;  
};
    