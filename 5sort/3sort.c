#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j+1] < arr[j])
                swap(&arr[j+1], &arr[j]);
        }
    }
}

void insertSort(int arr[], int n) {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int min_idx;
    for(int i = 0; i < n - 1; i++) {
        min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        if(min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

