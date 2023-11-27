#include <stdio.h> 
#include <stdlib.h> /* gives access to malloc */ 
#define SENT -1

// Structure that defines the node
typedef struct list_node_s { 
    int digit; 
    struct list_node_s *restp; // link to the next node
} list_node_t; 

// Declares a function that takes no parameters and returns a list_node_t type
list_node_t *get_list(void);
// Declares function that expects a pointer which points to a list_node_t type
int length_list(list_node_t *); 

int main(void) { 
    // Declares a pointer that points to a list_node_t type
    list_node_t *x;
    int y; 
    
    x = get_list();
    
    // Calculate and print the length of the list
    y = length_list(x); 
    printf("Length is: %d\n", y); 

    // Print the elements of the list
    printf("Elements in the list:\n");
    while (x != NULL) {
        printf("%d\n", x->digit);
        x = x->restp;
    }

    return 0;
}

/* 
* Forms a linked list of an input list of integers 
* terminated by SENT 
*/ 

// Function that creates the nodes
list_node_t *get_list(void){ 
    
    int data; 
    list_node_t *ansp;
    
    printf("Enter data (List ends if input = -1): "); 
    scanf("%d", &data); 
    if (data == SENT) { 
        ansp = NULL; 
    } 
    else{ 
        ansp = (list_node_t *)malloc(sizeof(list_node_t)); 
        ansp->digit = data; 
        ansp->restp = get_list(); 
    } 
    return (ansp); 
}; 

// Function that calculates the length of the list
int length_list(list_node_t *head) {
    int length = 0;
    
    while (head != NULL) {
        length++;
        head = head->restp;
    }

    return length;
}; 

        
    
    
    
    
