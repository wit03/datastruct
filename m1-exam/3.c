//65070503408 Jarukit Jintanasathirakul

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data[1000];
    int priority;
    struct Node *next;
} Node;

//a linked list with only pointer to store the address of next element from the first list followed by priority.
typedef struct pQueue {
    Node *head;
} pQueue;

pQueue *createQueue() {
    pQueue *pq = (pQueue*) malloc(sizeof(pQueue));
    pq->head = NULL;
    return pq;
}


//Sort on enqueue
//Enqueue(queue(pQueue), value(string pass by ref), priority(int))
void Enqueue(pQueue *pq, char *data, int priority) {
    //create a new node to store new data
    Node* newNode = (Node*) malloc(sizeof(Node));
    //copy string from parameter to new node
    strcpy(newNode->data,  data);
    //set the priority
    newNode->priority = priority;
    //set next to null
    newNode->next = NULL;
    if (pq->head == NULL) {
        //link the old queue to newNode address
        pq->head = newNode;
        return;
    }
    
    //lowest out first
    //Sorting on enqueue, if priority is less than the one store in the queue, put the new one in front
    if (priority < pq->head->priority) {
        newNode->next = pq->head;
        pq->head = newNode;
        return;
    }
    Node* current = pq->head;
    while (current->next != NULL && current->next->priority <= priority) { 
        current = current->next;
    }

    //traverse to the next element in list
    newNode->next = current->next;
    current->next = newNode;
}

void Dequeue(pQueue *pq) {
    if (pq->head == NULL) {
        //if queue is empty
        printf("None ");
        return;
    }
    Node* temp = pq->head;

    //print value
    printf("%s ", temp->data);
   
    //traverse next
    pq->head = pq->head->next;
    free(temp);
}

int main() {
    pQueue* pq = createQueue();

    char str[10000]; // the whole string
    char data[1000];  // each string value + priority
    int printCount = 0;

    //taking first line input
    gets(str);
    // taking second line input
    scanf("%d", &printCount);

    //Split string
    char *token = strtok(str, " ");
    strcpy(data, token); 

    //Split again so we get the priority part
    token = strtok(NULL, " ");
    int pri = atoi(token);

    while(token != NULL) {
        Enqueue(pq, data, pri);
        token = strtok(NULL, " ");
        if(token == NULL) {
            break; //break incase program found only string or priority but not both.
        }
            
        strcpy(data, token);
        token = strtok(NULL, " ");
        pri = atoi(token);
    }
    
    for(int i = 0; i < printCount; i++) {
        Dequeue(pq);
    }
    return 0;
}