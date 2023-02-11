#include <stdio.h>

int main()
{
    int row, column;
    scanf("%d", &row);
    scanf("%d", &column);

    int a[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int startRow = 0, startCol = 0;

    while (startRow < row && startCol < column)
    {
        for (int i = startCol; i < column; ++i)
        {
            printf("%d ", a[startRow][i]);
        }
        startRow++;
        for (int i = startRow; i < row; ++i)
        {
            printf("%d ", a[i][column - 1]);
        }
        column--;

        if (startRow < row)
        {
            for (int i = column - 1; i >= startCol; --i)
            {
                printf("%d ", a[row - 1][i]);
            }
            row--;
        }
        if (startCol < column)
        {
            for (int i = row - 1; i >= startRow; --i)
            {
                printf("%d ", a[i][startCol]);
            }
            startCol++;
        }
    }
    return 0;
}