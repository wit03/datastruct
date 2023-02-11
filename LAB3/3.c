#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

void push (Stack *top, int value) {
    Stack *new;
    new = (Stack*)malloc(sizeof(Stack));
    if(top == NULL) {
        printf("Stack Overflow\n");
        exit(-1);
    } else {
        new->next = top;
    }
    top = new;
}

int pop (Stack *top) {
    int t;
    Stack *p;
    if(top == NULL) {
        //stack is empty
        return -999999;
    }
    else {
        Stack *temp = top;
        int temp_data = top->value;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

int main() {
    Stack *top = NULL;

    push(top, 2);
    push(top, 3);
    push(top, 4);


    printf("%d", pop(top));


}