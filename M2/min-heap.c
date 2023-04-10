//65070503408 Jarukit Jintanasathirakul
#include <stdio.h>
#include <stdlib.h>

#define SIZE 101 //max heap size

int heap[SIZE];
int heapCurrSize = 0; //heap current size

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void perlocateUp(int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void perlocateDown(int index) {
    int left_child, right_child, min_index;
    while (1) {
        left_child = 2 * index + 1;
        right_child = 2 * index + 2;
        min_index = index;
        if (left_child < heapCurrSize && heap[left_child] < heap[min_index])
            min_index = left_child;
        if (right_child < heapCurrSize && heap[right_child] < heap[min_index])
            min_index = right_child;
        if (min_index == index)
            break;
        swap(&heap[index], &heap[min_index]);
        index = min_index;
    }
}

void Insert(int value) {
    heap[heapCurrSize] = value;
    perlocateUp(heapCurrSize);
    heapCurrSize++;
}

void PrintPre(int index) {
    if (index >= heapCurrSize) return;
    printf("%d ", heap[index]);
    PrintPre(2 * index + 1);
    PrintPre(2 * index + 2);
}



int main() {
    int size = 0;
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        int temp = 0;
        scanf("%d", &temp);
        Insert(temp);
    }
    PrintPre(0);
   
    return 0;
}
