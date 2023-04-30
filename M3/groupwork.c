#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

struct Heap{
	int* arr;
	int size;
	int capacity;
};

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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

double bubbleSort(int arr[], int n)
{
	int i,j;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    return duration;
}

double bubble_Flag_Sort(int arr[], int n)
{
	int i,j;
    clock_t start, end;
    start = clock();
    int flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
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

/*
* C Program to Implement CockTail Sort
*/
double cocktailSort(int arr[],int size){
    int swap = 1;
    int beg = 0;
    int tail = size - 1;
    int i, temp;
    clock_t start, end;
    start = clock();
    while(swap){
        swap = 0;
        for (i = beg; i < tail; ++i){
            if (arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = 1;
            }
        }
        if (!swap)
            break;
        swap = 0;
        --tail;
        for (i = tail - 1; i >= beg; --i){
            if (arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = 1;
            }
        }
        ++beg;
    }
	end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    return duration;
}

//Insertion sort
int binarySearch(int a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
 
    return low;
}

double BinarySort(int a[], int n)
{
	clock_t start, end;
    start = clock();
    int i, loc, j, k, key;
    for (i = 1; i < n; ++i) {
        j = i - 1;
        key = a[i];
 
        // find location where selected should be inserted
        loc = binarySearch(a, key, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    return duration;
}

double insertionSort(int arr[], int n)
{
	int i;
    clock_t start, end;
    start = clock();
    int key, j;
    for (i = 1; i < n; i++)
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
	int i,j;
    clock_t start, end;
    start = clock();
    int min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
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

//selection heap sort
void heapify(struct Heap* heap, int index){
	int left=index*2+1;
	int right=index*2+2;
	int min=index;
	
	if(left>=heap->size || left<0)
		left=-1;
	if(right>=heap->size || right<0)
		right=-1;
	
	if(left!=1 && heap->arr[left]<heap->arr[min])
		min=left;
	if(right!=1 && heap->arr[right]<heap->arr[min])
		min=right;
	
	if(min!=index){
		int temp=heap->arr[min];
		heap->arr[min]=heap->arr[index];
		heap->arr[index]=temp;
		
		heapify(heap,min);
	} 
}

struct Heap* create(int capacity){
	struct Heap* heap=(struct Heap*)malloc(sizeof(struct Heap));
	heap->arr=(int*)malloc(capacity*sizeof(int));
//	heap->arr=(int*)calloc(capacity,sizeof(int));
	heap->capacity=capacity;
	heap->size=0;
	return heap;
}

struct Heap* create_array(int capacity,int* nums){
	struct Heap* heap=(struct Heap*)malloc(sizeof(struct Heap));
	if(heap==NULL){
		printf("Memory error\n");
		return NULL;
	}
		
		
	heap->arr=(int*)malloc(sizeof(struct Heap));
	heap->size=0;
	heap->capacity=capacity;
	
	if(heap->arr==NULL)
		return NULL;
	int i;
	for(i=0;i<capacity;i++)
		heap->arr[i]=nums[i];
		
	heap->size=i;
	i=(heap->size-2)/2;
	while(i>=0){
		heapify(heap,i);
		i--;
	}
	return heap;
}

void insertHelper(struct Heap* heap,int index){
	int parent=(index-1)/2;
	if(heap->arr[parent]>heap->arr[index]){
		int temp=heap->arr[parent];
		heap->arr[parent]=heap->arr[index];
		heap->arr[index]=temp;
		
		insertHelper(heap,parent);
	}
}

void insert(struct Heap* heap,int data){
	if(heap->size<heap->capacity){
		heap->arr[heap->size]=data;
		insertHelper(heap,heap->size);
		heap->size++;
	}
}

int pop(struct Heap* heap){
	int del;
	if(heap->size==0){
		printf("pop empty\n");
		return -1;
	}
	del=heap->arr[0];
	heap->arr[0]=heap->arr[heap->size-1];
	heap->size--;
	heapify(heap,0);
	return del;
}

void print(struct Heap* heap){
	int i;
	for(i=0;i<heap->size;i++){
		printf("%d ",heap->arr[i]);
	}
	printf("\n");
}

double selection_Heap_Sort(int arr[], int n,struct Heap *heap)
{
	int i,j;
    clock_t start, end;
    start = clock();
    int min,min_idx;
    for(i=0;i<n;i++){
    	insert(heap,arr[i]);
	}
    for (i = 0; i < n-1; i++)
    {
    	min=pop(heap);
        for(j=i;j<n;j++){
    		if(min==arr[j]){
    			min_idx=j;
    			break;
			}
		}
        swap(&arr[min_idx], &arr[i]);
    }
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    return duration;
}

void printArray(int arr[], int size)
{
	int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
	struct Heap *heap=create(SIZE);
	int i;
    int bestCase[SIZE] = {0};

    int worst_bubble[SIZE] = {0};
    int worst_bubble_flag[SIZE] = {0};
    int worst_cocktail[SIZE] = {0};
    int worst_insertion[SIZE] = {0};
    int worst_binary[SIZE] = {0};
    int worst_selection[SIZE] = {0};
    int worst_selection_heap[SIZE]={0};

    int avg_bubble[SIZE] = {0};
    int avg_bubble_flag[SIZE] = {0};
    int avg_cocktail[SIZE] = {0};
    int avg_insertion[SIZE] = {0};
    int avg_binary[SIZE] = {0};
    int avg_selection[SIZE] = {0};
    int avg_selection_heap[SIZE] = {0};

    createRandom(avg_bubble, SIZE);
    

    for (i = 0; i < SIZE; i++)
    {
    	avg_bubble_flag[i] = avg_bubble[i];
    	avg_cocktail[i] = avg_bubble[i];
        avg_insertion[i] = avg_bubble[i];
        avg_binary[i] = avg_bubble[i];
        avg_selection[i] = avg_bubble[i];
        avg_selection_heap[i] = avg_bubble[i];
        bestCase[i] = i;
    }

    for (i = 0; i < SIZE; i++)
    {
        worst_bubble[i] = avg_bubble[SIZE - 1 - i];
        worst_bubble_flag[i] = avg_bubble_flag[SIZE - 1 - i];
        worst_cocktail[i] = avg_cocktail[SIZE - 1 - i];
        worst_insertion[i] = avg_insertion[SIZE - 1 - i];
        worst_binary[i] = avg_binary[SIZE - 1 - i];
        worst_selection[i] = avg_selection[SIZE - 1 - i];
        worst_selection_heap[i] = avg_selection_heap[SIZE - 1 - i];
    }

    printf("Best Case\n");
    printf("Bubble Sort:          %lf\n", bubbleSort(bestCase, SIZE));
    printf("Bubble Flag Sort:     %lf\n", bubble_Flag_Sort(bestCase, SIZE));
    printf("Cocktail Sort:        %lf\n", cocktailSort(bestCase, SIZE));
    printf("Insertion Sort:       %lf\n", bubbleSort(bestCase, SIZE));
	printf("Binary Insertion Sort:%lf\n", bubbleSort(bestCase, SIZE));
    printf("Selection Sort:       %lf\n", selectionSort(bestCase, SIZE));
    printf("Selection Heap Sort:  %lf\n\n", selection_Heap_Sort(bestCase, SIZE, heap));

    printf("Average Case\n");
    printf("Bubble Sort:          %lf\n", bubbleSort(avg_bubble, SIZE));
    printf("Bubble Flag Sort:     %lf\n", bubble_Flag_Sort(avg_bubble_flag, SIZE));
    printf("Cocktail Sort:        %lf\n", cocktailSort(avg_cocktail, SIZE));
    printf("Insertion Sort:       %lf\n", insertionSort(avg_insertion, SIZE));
    printf("Binary Insertion Sort:%lf\n", BinarySort(avg_binary, SIZE));
    printf("Selection Sort:       %lf\n", selectionSort(avg_selection, SIZE));
    printf("Selection Heap Sort:  %lf\n\n", selection_Heap_Sort(avg_selection, SIZE, heap));

    printf("Worst Case\n");
    printf("Bubble Sort:          %lf\n", bubbleSort(worst_bubble, SIZE));
    printf("Bubble Flag Sort:     %lf\n", bubble_Flag_Sort(worst_bubble_flag, SIZE));
    printf("Cocktail Sort:        %lf\n", cocktailSort(worst_cocktail, SIZE));
    printf("Insertion Sort:       %lf\n", insertionSort(worst_insertion, SIZE));
    printf("Binary Insertion Sort:%lf\n", BinarySort(worst_binary, SIZE));
    printf("Selection Sort:       %lf\n", selectionSort(worst_selection, SIZE));
    printf("Selection Heap Sort:  %lf\n\n", selection_Heap_Sort(worst_selection, SIZE, heap));
    
	//printArray(worst_cocktail, SIZE);

    return 0;
}