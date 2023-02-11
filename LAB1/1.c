#include <stdio.h>

int main() {
    float marks[20][5];
    float sum[5] = {0};

    for(int i = 0; i < 20; i++) {
        scanf("%f %f %f %f %f", &marks[i][0], &marks[i][1], &marks[i][2], &marks[i][3], &marks[i][4]);
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 20; j++) {
            sum[i] += marks[j][i];
        }
    }
    for(int i = 0; i < 5; i++) {
        int temp = sum[i]/20 * 100;
        if(temp % 100 == 0) {
            printf("%.f\n", sum[i]/20);
        } else if (temp % 10 == 0) {
            printf("%.1f\n", sum[i]/20);
        } else {
            printf("%.2f\n", sum[i]/20);
        }
        temp = 0;
    }
    return 0;
}