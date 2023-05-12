#include <stdio.h>
// Logic
// 1st loop: traverse from 1 to n-1
// 2nd loop: traverse from key back to 0
//
// key = the latest sorted element


void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1; //backward to 0

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[4] = {4,5,1,3};
    insertSort2(arr, 4);
    int arr2[4] = {3,6,2,1};
    bubble(arr2, 4);

    printArray(arr2,4);
    printArray(arr, 4);
    
    
    return 0;
}