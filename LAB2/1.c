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

void printList(ListNode *list) {
    int prev, curr;
    int count = 0;
    ListNode *print  = list;

    //loop until there's no more list
    while(print != NULL) {
        curr = print->val;
        //check if the the next list existed
        if(print->next != NULL) {
            //current pos != prev and next pos, print
            if(prev != curr && curr != print->next->val) {
                printf("%d ", curr);
                count++;
            }
        } else {
            //in case of last list, if it's != prev, print 
            if(prev != curr) {
                printf("%d ", curr);
                count++;
            }
        }
        prev = curr;
        print = print->next;
    }

    if(count == 0) {
         printf("None");
    }
}

int main() {
    char str[1000];

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
    printList(list);
    
    return 0;
}