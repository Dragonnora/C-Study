// last in, first out data structure 

#include <stdio.h>
#include <stdlib.h> // for exit function
#define MAX 6
int top = 4;

void push(int data, int array[], int* top) {
    if (*top < MAX - 1) {
        (*top)++;
        array[*top] = data;
    } else {
        printf("Stack overflow."); 
    }
}

void pop(int array[], int* top){
    
    if (*top == -1){
        printf("Stack overflow.");
        exit (1); 
    } 
    
    (*top)--; 
    
}

int main() {
    int array[MAX] = {1, 2, 3, 4, 5};
    
    // test print: before push
    for (int i = 0; i <= top; i++) {
        printf(" %d,", array[i]);
    }
    printf("\n");

    // push function
    push(6, array, &top);

    // test print: after push 
    for (int i = 0; i <= top; i++) {
        printf(" %d,", array[i]);
    }
    printf("\n");
    
    // pop function
    pop(array, &top);
    
    // test print: after pop 
    for (int i = 0; i <= top; i++){
        printf(" %d,", array[i]); 
        
    }
    
    return 0;
}
