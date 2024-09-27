# 🧮 Sorting Algorithms: Insertion and Merge

This project implements two sorting algorithms, **Insertion Sort** and **Merge Sort**, to sort multiple arrays and measure their performance in terms of comparisons and value assignments (referred to as "swaps" in the professor's instructions). The results are output in a specific format as described below.

## 📝 Problem Description

You are given `Q`, the number of arrays. For each array, the size `N` is provided, followed by the elements of the array. The program sorts each array using both **Insertion Sort** and **Merge Sort** and prints the number of comparisons and assignments made during the sorting process.

### 📊 Output Format

For each sorting method, the program outputs:

`M N T C`

Where:
- **M**: Sorting method used (`I` for Insertion Sort and `M` for Merge Sort).
- **N**: Size of the array.
- **T**: Number of assignments (referred to as "swaps").
- **C**: Number of comparisons made.

## ⚙️ Algorithms

### 🔄 Insertion Sort
The **Insertion Sort** algorithm iterates through each element in the array and inserts it into its correct position relative to the already sorted part of the array. During this process, the program tracks:
- **Assignments (T)**: The number of times a value is inserted or moved in the array.
- **Comparisons (C)**: The number of comparisons made between elements.

### ⚔️ Merge Sort
The **Merge Sort** algorithm divides the array into smaller sub-arrays, sorts these sub-arrays recursively, and then merges them back together in sorted order. The program tracks:
- **Assignments (T)**: The number of times elements from sub-arrays are assigned to the original array during the merging process.
- **Comparisons (C)**: The number of comparisons made between elements of the two sub-arrays during merging.

