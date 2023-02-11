#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *createNode(int data)
{
    ListNode *start = (ListNode *)malloc(sizeof(ListNode) + 1);
    start->val = data;
    start->next = NULL;
    return start;
}

ListNode *insertEnd(ListNode *start, int val)
{
    ListNode *pNew = createNode(val);
    if (start == NULL)
        return pNew;

    ListNode *current = start;
    while (current->next != NULL)
        current = current->next;
    current->next = pNew;
    return start;
}

int countList(ListNode *start)
{
    ListNode *list = start;
    int count = 0;
    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    return count;
}

void dropList(ListNode *start, int pos)
{ // pos is start with 1 to N
    ListNode *list = start;
    int count = 0;

    while (list != NULL)
    {
        count++;
        if (count == pos)
        {
            list->next = list->next->next;
        }
        list = list->next;
    }
}

void printList(ListNode *list)
{
    int prev, curr;
    ListNode *print = list;

    // loop until there's no more list
    while (print != NULL)
    {
        curr = print->val;
        printf("%d", curr);
        print = print->next;
    }
}

ListNode *delete(ListNode *head, int pos)
{
    ListNode *temp = head;
    ListNode *clone = NULL;
    for (int i = 0; i < countList(head); i++)
    {
        if (i != pos)
        {
            clone = insertEnd(clone, temp->val);
        }
        temp = temp->next;
    }
    return clone;
}

ListNode *reverseList(ListNode *temp)
{
    ListNode *current = temp;
    ListNode *prevNode = NULL, *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    return prevNode;
}

int isPalindrome(ListNode *current, int size)
{
    ListNode *head = current;
    ListNode *ptr = current;
    int flag = 1;

    // Store the mid position of the list
    int mid = (size % 2 == 0) ? (size / 2) : ((size + 1) / 2);

    // Finds the middle node in given singly linked list
    for (int i = 1; i < mid; i++)
    {
        ptr = ptr->next;
    }

    // Reverse the list after middle node to end
    ListNode *revHead = reverseList(ptr->next);

    while (head != NULL && revHead != NULL)
    {
        if (head->val != revHead->val)
        {
            flag = 0;
            break;
        }
        head = head->next;
        revHead = revHead->next;
    }

    if (flag == 1)
        return 1;
    else
        return 0;
}

int calculate(ListNode *list, int listLength)
{
    ListNode *cal = list;
    if (isPalindrome(delete (cal, -1), listLength) == 1)
    {
        printf("None");
        return 1;
    }
    else
    {
        for (int i = 0; i < listLength; i++)
        {
            if (isPalindrome(delete (cal, i), listLength - 1) == 1)
            {
                printf("%d", i);
                return 1;
            }
        }
    }
    printf("None");
    return 1;
}

int main()
{
    char str[1000];

    ListNode *list = NULL;

    // take whole string input
    gets(str);

    // seperate string
    char *token = strtok(str, " ");

    // stop taking input when found "END"
    while (strcmp(token, "END") != 0)
    {
        list = insertEnd(list, atoi(token)); // Insert converted str->int to list
        token = strtok(NULL, " ");
    }

    calculate(list, countList(list));
    return 0;
}