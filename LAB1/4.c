#include <stdio.h>

int main() {
    int width, height;
    scanf("%d %d", &height, &width);
    
    int arr[height][width];
    int odd[height*width], even[height*width];

    int pushtoEven = 0;
    int pushtoOdd = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            scanf( "%d" ,&arr[i][j]);
        }
    }

    for(int i = 0; i < height*width; i++) {
        odd[i] = 10001;
        even[i] = 10001;
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if (arr[i][j] % 2 == 0) {
                //even
                even[pushtoEven] = arr[i][j];
                pushtoEven++;
            } else {
                //odd
                odd[pushtoOdd] = arr[i][j];
                pushtoOdd++;
            }
        }
    }

    if(odd[0] == 10001) {
        printf("None");
    } else {
        for(int i = 0; i < pushtoOdd; i++) {
            printf("%d ", odd[i]);
        } 

    }

    printf("\n");

    if(even[0] == 10001) {
        printf("None");
    } else {
        for(int i = 0; i < pushtoEven; i++) {
            printf("%d ", even[i]);
        }
    }

    return 0;
}