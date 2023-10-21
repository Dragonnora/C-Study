#include <stdio.h>

int add(int a, int b){
    
   int sum = a + b; 
   
   return sum; 
    
}

int subtract(int a, int b){
    
    int sum = a - b; 
    
    return sum;
}

int multiply(int a, int b){
    
    int product = a * b; 
    
    return product; 
}

/* doesn't take arguments but returns a function that takes two
   int arguments and returns an int value */ 
int (*select_operation())(int, int){
    
    int selection; 
    printf("Select an operation:\n"); 
    printf("1) Addition\n");
    printf("2) Subtraction\n"); 
    printf("3) Multiplication\n"); 
    printf("Enter selection: "); 
    scanf("%d", &selection); 
    
    if (selection == 1) return add; 
    if (selection == 2) return subtract; 
    if (selection == 3) return multiply; 
    
}


int main()
{
    // assigns the result of select_operation to our function pointer
    int (*operation)(int, int) = select_operation(); 
    
    
    printf("Answer: %d", operation(20, 5)); 
    

    return 0;
}
