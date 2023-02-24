//65070503408 Jarukit Jintanasathirakul

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeDuplicate(int arr[], int *size) {
    //traverse through array
    for (int i = 0; i < *size-1; i++) {
        //continue traversing for the element that haven't been checked
      for (int j = i+1; j < *size; j++) {
        //check if element is equal
         if (arr[i] == arr[j]) {
            //replace the second equal element by the rest of element (shift left)
            for (int k = j; k < *size-1; k++) {
               arr[k] = arr[k+1];
            }
            (*size)--;
            j--;
         }
      }
   }

}


int main() {
    char str[1000];
    int arr[1000];
    int count = 0; //length of input
    
    //parse input
    gets(str);
    char *token = strtok(str, " ");

    while(token != NULL) {
        arr[count] = atoi(token);
        count++;
        token = strtok(NULL, " ");
    }

    removeDuplicate(arr, &count);

    for(int i = 0; i < count; i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}


