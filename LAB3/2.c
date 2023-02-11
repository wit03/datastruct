#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct Stack {
    char st[MAXSIZE][10];
    int top;
} Stack;

void create (Stack *s) {
    s->top = -1;
}

void push(Stack *s, char element[]) {
    if(s->top == (MAXSIZE-1)) {
        printf("Stack overflow");
        exit(-1);
    } else {
        s->top++;
        strcpy(s->st[s->top],element);
    }
}

char *pop (Stack *s) {
    if(s->top == -1) {
        printf("\nStack underflow");
        exit(-1);
    } else {
        return (s->st[s->top--]);
    }
}

int main() {
    Stack *s;
    s = (Stack*)malloc(sizeof(Stack));
    create(s);
    
    char str[1000];
    int count = 0;
    gets(str);
    char *token = strtok(str, " ");

    while(token != NULL) {
        count++;
        push(s, token);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
    //print reverse
    for(int i = 0; i < count; i++) {
        printf("%s ", pop(s));
    }

    return 0;
}