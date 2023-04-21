#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }   
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int _[8] = {89,45,68,5,90,34,17,25};
    int __[8] = {89,45,68,5,90,34,17,25};
    int ___[8] = {89,45,68,5,90,34,17,25};
    int size = 8;
    
    bubbleSort(_, size);
    printf("Result from Bubble Sort: ");
    printArray(_, size);

    insertionSort(__, size);
    printf("Result from Insertion Sort: ");
    printArray(__,size);

    selectionSort(___, size);
    printf("Result from Selection Sort: ");
    printArray(___, size);
    return 0;
}