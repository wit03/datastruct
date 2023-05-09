// Logic:
// 2 nested loop traverse in 
// ***
// **
// *
// if n > n+1 then swap 

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
	int i,j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) //n > n+1 then swap
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort2(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - j; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void swap3(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(int arr[], int n) {
    for(int i = 0; i < n -1; i++) {
        for(int j = 0; j = n -1 -i; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int swap4(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort4(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; i < n - 1 - i; j++) {
            if(ar[j] > ar[j+1])
                swap(&ar[j], &ar[j+1]);
        }
    }
}