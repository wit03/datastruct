#include <stdio.h>
int main() {
    int size, sum=0;
    scanf("%d", &size);

    int arr[size][size];

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < size; i++) {
        sum += arr[i][i];
    }

    printf("%d", sum);

    return 0;
}