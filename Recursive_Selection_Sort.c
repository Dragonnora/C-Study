
#include <stdio.h>

void sortArray(int array[], int n, int index){
    
    // If/when the stack is full
    if (index == n - 1)  
        return;
    
    // Stores position of largest element in unsorted array
    int maxIndex = index;
    
    // Loops through unsorted elements in the array
    for (int i = index + 1; i < n; i++){
        
        /* If element in next position is greater than element in maxIndex,
            change position of maxIndex */ 
        if (array[i] > array[maxIndex])
            maxIndex = i; 
    }
    
    // Index position should always be position of maxIndex
    if (maxIndex != index){
        
        // Swap 
        int temp = array[index]; 
        array[index] = array[maxIndex]; 
        array[maxIndex] = temp;
            
    }
    
    // Recursive call 
    sortArray(array, n, index+1); 
        
}

int main(){
    
    // The unsorted array
    int array[5] = {1, 3, 5, 2, 4};
    
    /* Determintes size of array at runtime 
    int length = sizeof(array) / sizeof(array[0]); */ 
    
    // Since I know the size of my array at compile-time... 
    int length = 5; 
    
    // Gives function array with size 5 at index 0 
    sortArray(array, length, 0); 
    
    printf("Sorted array: "); 
    for (int i = 0; i < length; i++){
        printf(" %d,", array[i]); 
    } 
        
}
