#include <stdio.h>

int main() {
    int size = 0;
    int temp = 0;
    scanf("%d", &size);
    int arr[size];
    int *min;
    int *max;
    int *secMin;
    int *secMax;

    min = secMin = &arr[size-1];
    max = secMax = &arr[0];

    //take input
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] > *max) {
            secMax = max;
            max = &arr[i];
        } else if (arr[i] > *secMax) {
            secMax = &arr[i];
        }

        if (arr[i] < *min) {
            secMin = min;
            min = &arr[i];
        } else if (arr[i] < *secMin) {
            secMin = &arr[i];
        }
    }

    temp = *secMin;
    *secMin = *secMax;
    *secMax = temp;

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}