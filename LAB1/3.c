#include <stdio.h>

int main() {
    float marks[20][5];
    float sum[20] = {0};
    int failCount = 0;

    for(int i = 0; i < 20; i++) {
        scanf("%f %f %f %f %f", &marks[i][0], &marks[i][1], &marks[i][2], &marks[i][3], &marks[i][4]);
    }
    
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 5; j++) {
            sum[i] += marks[i][j];
        }
    }
    for(int i = 0; i < 20; i++) {
        if(sum[i]/5 < 50) {
            failCount++;
        }
    }

    printf("%d", failCount);
    return 0;
}