#include <stdio.h>

int function_q(int *); 


// *pointer points to address
int function_t(int *pointer){
    
    // changing values stored in address
    *pointer = *pointer + 5;
    
    printf("Address of number: %p\n", (void*)pointer);
    
    // address of ptr that points to number address
    printf("Address of pointer: %p\n", (void*)&pointer);
    
    /* note: pointers have their own addresses. 
       they are variables that memory addresses of 
       other variables */ 
    
    // dereferences pointer and returns value
    return *pointer;  
}


int main(){
    
    int number = 5; 
    
    // int *ptr_to_number = &number; 
    
    int *ptr_to_number; // declare ptr that points to integer data type
    ptr_to_number = &number; // assigns address of 'number' to ptr 
    
    printf("Number: %d\n", number);
    
    /*
        void - ptr type that can hold address of any data type
        (void*) - 'printf' expects ptr to void
        %p expects void* type. Format specifier used for printing memory addresses 
    */ 
    printf("Address: %p\n", (void*)&number); 
    /* (void*) tells program to take whatever ptr data type currently pointing to address and 
        convert it to a void ptr type */ 
    
    // dereferences pointer
    printf("Pointer to number: %d\n", *ptr_to_number); 
    
    // pass address to function
    int new_number = function_t(ptr_to_number);
    
    /* could also write:
        int new_number = function_t(&number); 
        
        both have the same result but different ways of doing it. 
        
        - &number gives function_t access to memory address 
        - ptr_to_number gives function_t access to memory through variable containing address
        
        both give direct access to address
    */ 
    
    printf("New number: %d\n", new_number); 
    
    int revert_to_previous = function_q(&new_number);
    
    printf("Revert to previous: %d\n", revert_to_previous); 
    
    
    return 0; 
}

int function_q(int *number)
{
    *number = *number - 5; 
    return *number;  
}
