#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int val;
    struct ListNode  *next;
} ListNode;

ListNode *createNode(int data) {
    ListNode *start = (ListNode*)malloc(sizeof(ListNode)+1);
    start->val = data;
    start->next = NULL;
    return start;
}

ListNode *insertEnd(ListNode *start, int val) {
    ListNode *pNew = createNode(val);
    if(start == NULL) return pNew;

    ListNode *current = start;
    while(current->next != NULL)
        current = current->next;
    current->next = pNew;
    return start;    
}

void printList(ListNode *list, int start, int end) {
    int count = 0;
    ListNode *print  = list;

    ListNode* prev = NULL;
    ListNode* curr = print;

    for(int i = 1; curr != NULL && i < start;i++) {
        prev=curr;
        curr = curr->next;
    }

    ListNode* s = curr;
    ListNode* e = NULL;

    for(int i = 1; curr != NULL && i <= end - start +1; i++) {
        ListNode* next = curr->next;
        curr -> next = e;
        e = curr;
        curr = next;
    }

    if (s) {
        s->next = curr;
        if(prev != NULL) {
            prev->next = e;
        }
        else {
            list = e;
        }
    }

    //loop until there's no more list
    while(list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }

}

int main() {
    char str[1000];
    int sPoint,ePoint;

    ListNode *list = NULL;
    
    //take whole string input
    gets(str);
    
    //seperate string
    char *token = strtok(str, " ");

    //stop taking input when found "END"
    while (strcmp(token, "END") != 0) {
        list = insertEnd(list, atoi(token)); //Insert converted str->int to list
        
        token = strtok(NULL, " ");
    }

    scanf("%d %d", &sPoint, &ePoint);
    printList(list, sPoint, ePoint);
    return 0;
}