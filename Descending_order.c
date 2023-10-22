#include <stdio.h>
#include <stdlib.h> // for memory allocation

// prototype
void order(int *ptr_numbers[], int arraySize); 

int main(){
    
    int numbers[10];
    int *ptr_numbers[10]; 
    int arraySize = 10; 
    
    // get input from user
    for (int i = 0; i < 10; i++){
        
        printf("Enter number: "); 
        scanf("%d", &numbers[i]); 
        
    }
    
    // prints numbers entered by user
    printf("\n"); 
    for (int i = 0; i < 10; i++){
        
        printf("%d, ", numbers[i]);
    }
    
    // assigns pointer variable to each element address in array
    for (int i = 0; i < 10; i++){
        
        ptr_numbers[i] = &numbers[i]; 
    }
    
    // calls order function
    order(ptr_numbers, arraySize); 
    
    
    // prints numbers in descending order
    printf("\n"); 
    for (int i = 0; i < 10; i++){
        
        printf("%d, ", *ptr_numbers[i]);
    }
    
    return 0; 
}

// uses bubble sorting algorithm to put values in descending order
void order(int *ptr_numbers[], int arraySize) {
    int temp;

    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (*ptr_numbers[j] < *ptr_numbers[j + 1]) { // Compares values

                // values switch places
                temp = *ptr_numbers[j];
                *ptr_numbers[j] = *ptr_numbers[j + 1];
                *ptr_numbers[j + 1] = temp;
            }
        }
    }
    
}




