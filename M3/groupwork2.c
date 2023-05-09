#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void createRandom(int arr[], int size)
{
	int i,j;
    int rand_num;
    int is_unique;

    srand(time(NULL));

    for (i = 0; i < size; i++)
    {
        do
        {
            rand_num = rand() % size + 1; // Generate a number between 1 and size
            is_unique = 1;                // Assume the number is unique

            for(j = 0; j < i; j++)
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

void mergeReverse(int arr[], int left[], int right[], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++)
        arr[i] = left[i];
    for (j = 0; j < m; j++, i++)
        arr[i] = right[j];
}

void separate(int arr[], int n) {
    if (n <= 1)
        return;

    if (n == 2) {
        int swap = arr[0];
        arr[0] = arr[1];
        arr[1] = swap;
        return;
    }

    int i, j;
    int m = (n + 1) / 2;
    int* left = (int*)malloc(m * sizeof(int));
    int* right = (int*)malloc((n - m) * sizeof(int));

    for (i = 0, j = 0; i < n; i = i + 2, j++) //Storing alternate elements in left subarray
        left[j] = arr[i];

    for (i = 1, j = 0; i < n; i = i + 2, j++) //Storing alternate elements in right subarray
        right[j] = arr[i];

    separate(left, m);
    separate(right, n - m);
    mergeReverse(arr, left, right, m, n - m);
    free(left);
    free(right);
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = l; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // find the middle point
        int m = l + (r - l) / 2;

        // sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // merge the sorted halves
        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
      
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

double mergeTimer(int arr[], int l, int r) {
    clock_t start, end;
    start = clock();
    mergeSort(arr, l, r);
    end = clock();

    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    return duration;
}

double quickTimer(int arr[], int low, int high) {
    clock_t start, end;
    start = clock();
    quickSort(arr, low, high);
    end = clock();

    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    return duration;
}

int main() {
    int avgCaseMerge[SIZE] = {0};
    int avgCaseQuick[SIZE] = {0};

    int worstCaseMerge[SIZE] = {0};
    int worstCaseQuick[SIZE] = {0};

    createRandom(avgCaseMerge, SIZE);

    for(int i = 0; i < SIZE; i++) {
        worstCaseMerge[i] = i;
        avgCaseQuick[i] = avgCaseMerge[i];
        worstCaseQuick[i] = SIZE - i;
    }

    separate(worstCaseMerge, SIZE);
    
    printf("Average Case\n");
    printf("Merge Sort: %lf\n", mergeTimer(avgCaseMerge, 0, SIZE-1));
    printf("Quick Sort: %lf\n", quickTimer(avgCaseQuick, 0, SIZE-1));

    printf("Worst Case\n");
    printf("Merge Sort: %lf\n", mergeTimer(worstCaseMerge, 0, SIZE-1));
    printf("Quick Sort: %lf\n", quickTimer(worstCaseQuick, 0, SIZE-1));

    return 0;
}
