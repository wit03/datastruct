//65070503408 Jarukit Jintanasathirakul
#include <stdio.h>

int size = 5;
int tree[10000] = {0};

int getParent(int index)
{
    if (tree[index] != 0 && index > 1 && index <= size)
        return index / 2;
    return -1;
}
int getRIghtChild(int index)
{
    if (tree[index] != 0 && ((2 * index) + 1) <= size)
        return (2 * index) + 1;
    // right child doesn't exist
    return -1;
}
int getLeftChild(int index)
{
    if (tree[index] != 0 && (2 * index) <= size)
        return 2 * index;
    // left child doesn't exist
    return -1;
}
void PrintPre(int index)
{
    if (index > 0 && tree[index] != 0)
    {
        printf("%d ", tree[index]);     
        PrintPre(getLeftChild(index));  
        PrintPre(getRIghtChild(index)); 
    }
}
void PrintPost(int index)
{
    if (index > 0 && tree[index] != 0)
    {
        PrintPost(getLeftChild(index));  
        PrintPost(getRIghtChild(index)); 
        printf("%d ", tree[index]);       
    }
}
void PrintIn(int index)
{
    if (index > 0 && tree[index] != 0)
    {
        PrintIn(getLeftChild(index));  
        printf("%d ", tree[index]);     
        PrintIn(getRIghtChild(index)); 
    }
}

int Search(int value) {
    for(int i = 1; i <= size; i++) {
        if(value == tree[i]) {
            printf("Duplicate\n");
            return 2;
        }
    }
    return 1;
}

void Insert() {
    int temp = 0; //temporary store the 
    int Dupcount = 0; //count the duplicate

    for(int i = 1; i <= size; i++) {
        scanf("%d", &temp);
        if(Search(temp) != 2) {
            tree[i-Dupcount] = temp;
        } else {
            Dupcount++;
        }
        temp = 0;
    }
}

int main()
{
    scanf("%d", &size);
    
    //insert function
    Insert();

    /*print the tree in each traversal order*/    
    PrintPre(1);
    printf("\n");
    PrintIn(1);
    printf("\n");
    PrintPost(1);

    return 0;
}