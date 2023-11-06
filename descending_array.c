#include <stdio.h>
#define size_a 5

void sort(int [], int); 
int get_min_range(); 
int get_min_index(); 


int main()
{
    // initializes array
    int array[size_a] = {5, 9, 11, 2, 1};
    
    // calls sorting array
    sort(array, size_a); 
    

    return 0;
}

void sort(int array[], int size){
    
    int temp, min_index, i, j; 
    int n = size;                   // 5
    
    for (i = 0; i < n - 1; i++){
        min = get_min_index(array, i, n - 1);   // 1st iteration: gets min index of the entire array
                                               // every iteration after gets min index of new subarray
        
        
         
    }
}

int get_min_index(int array[], int first_element, int last_element){
    
    int min_index = first_element;
    
    for (int i = first_element + 1; i <= last_element; i++){
        if (array[i] < array[min_index])                              /*  if next element in the array is less than the min, the index value
                                                                    of that element becomes the new min */ 
            min_index = i;
    }
    
    return min_index;  // returns min index of the subarray
    
    
}
