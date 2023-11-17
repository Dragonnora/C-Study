

#include <stdio.h>
#include <stdlib.h> // malloc function

struct node {
    
   int data;
   struct node *link; // self-referencing. points to struct node
    
}; 



int main()
{
    
    /* initialize ptr to NULL to so program doesn't assign it invalid 
        memory location. if we dereference ptr (try to access memory it points to)
        and it contains a garbage value, it can lead to undefined behavior 
    */ 
    
    struct node *head = NULL; // ptr that points to struct node. initialize to 'no address'
    head = (struct node*)malloc(sizeof(struct node)); // typecast is optional. converts to ptr that points to struct node 
    
    // if memory allocation fails 
    if (head == NULL){
        
        /*
            fprintf - function in c that lets you print to specified filestream
            stderr - predefined file stream for standard error output
        */ 
        fprintf(stderr, "Memory allocation failed\n"); 
        return 1; // error code
        
    }
    
    head -> data = 45; // accesses node through head ptr to get data 
    head -> link = NULL; // accesses node through head ptr to get link
    
    printf("%d", head->data); 
    
    // frees allocated memory before program exits. we do this to avoid memory leaks
    free(head); 

    return 0;
}

// only way to access first node of list is through pointer
