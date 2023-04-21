#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30000

void createRandom(int arr[], int size)
{
    int rand_num;
    int is_unique;

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        do
        {
            rand_num = rand() % size + 1; // Generate a number between 1 and size
            is_unique = 1;                // Assume the number is unique

            for (int j = 0; j < i; j++)
            {
                if (arr[j] == rand_num)
                {
                    is_unique = 0; // Number is not unique
                    break;
                }
            }
        } while (!is_unique);
        arr[i] = rand_num;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

double bubbleSort(int arr[], int n)
{
    clock_t start, end;
    start = clock();
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    return duration;
}

double insertionSort(int arr[], int n)
{
    clock_t start, end;
    start = clock();
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    return duration;
}

double selectionSort(int arr[], int n)
{
    clock_t start, end;
    start = clock();
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    return duration;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int bestCase[SIZE] = {0};

    int worst_bubble[SIZE] = {0};
    int worst_insertion[SIZE] = {0};
    int worst_selection[SIZE] = {0};

    int avg_bubble[SIZE] = {0};
    int avg_insertion[SIZE] = {0};
    int avg_selection[SIZE] = {0};

    createRandom(avg_bubble, SIZE);
    

    for (int i = 0; i < SIZE; i++)
    {
        avg_insertion[i] = avg_bubble[i];
        avg_selection[i] = avg_bubble[i];
        bestCase[i] = i;
    }

    for (int i = 0; i < SIZE; i++)
    {
        worst_bubble[i] = avg_bubble[SIZE - 1 - i];
        worst_insertion[i] = avg_insertion[SIZE - 1 - i];
        worst_selection[i] = avg_selection[SIZE - 1 - i];
    }

    printf("Best Case\n");
    printf("Bubble Sort: %lf\n", bubbleSort(bestCase, SIZE));
    printf("Insertion Sort: %lf\n", bubbleSort(bestCase, SIZE));
    printf("Selection Sort: %lf\n\n", selectionSort(bestCase, SIZE));

    printf("Average Case\n");
    printf("Bubble Sort: %lf\n", bubbleSort(avg_bubble, SIZE));
    printf("Insertion Sort: %lf\n", insertionSort(avg_insertion, SIZE));
    printf("Selection Sort: %lf\n\n", selectionSort(avg_selection, SIZE));

    printf("Worst Case\n");
    printf("Bubble Sort: %lf\n", bubbleSort(worst_bubble, SIZE));
    printf("Insertion Sort: %lf\n", insertionSort(worst_insertion, SIZE));
    printf("Selection Sort: %lf\n\n", selectionSort(worst_selection, SIZE));

    return 0;
}