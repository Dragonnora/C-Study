#include <stdio.h>


// A structure that contains two data types (a node)  
typedef struct node_s { 
char current[3];            // An array of characters that stores the current
int volts;              // An integer that stores the voltage
struct node_s *linkp;      // Declares a pointer to the next node in the linked list
} node_t;              
// The name of the node

// struct node_s *linkp is a pointer that provides access to the next node in the list
