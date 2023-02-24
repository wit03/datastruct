//65070503408 Jarukit Jintanasathirakul
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
    char value;
    struct Stack *next;
} Stack;

void push (Stack **top, char value) {
    Stack *new;
    new = (Stack*)malloc(sizeof(Stack));
    new->value = value;
    new->next = *top;
    *top = new;
}

char pop (Stack **top) {
    Stack *temp;

    if(*top == NULL) {
        printf("None");
        return 0;
    }
    else {
        temp = *top;
        *top = (*top)->next;
        return temp->value;
    }
}


int main() {
    //create stack
    Stack *top = NULL;
    Stack *top2 = NULL;

    //create a blank string for passing input
    char str[1000];
    char str2[1000];

    //taking input
    scanf("%s", str);
    scanf("%s", str2);

    //find the length of 2 strings
    int count = strlen(str);
    int count2 = strlen(str2);

    //push the element in the char[] to each stack
    for(int i = 0; i < count; i++) {
        push(&top, str[i]);
    }

    for(int i = 0; i < count2; i++) {
        push(&top2, str2[i]);
    }
    
    //print
    for(int i = 0; i < count; i++) {
        //compare the popped value and print the result
        if(pop(&top) != pop(&top2)) {
            printf("1");
            return 0;
        }
    }
    printf("0");

    return 0;
}