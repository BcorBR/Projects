#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdbool.h>
#include <stdio.h>

void printArray(int arr[], int size);

void swap(int *x, int *y);

void bubble_sort(int arr[], int size);

#endif