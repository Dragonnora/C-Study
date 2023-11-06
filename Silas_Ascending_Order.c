#include <stdio.h>
#define len 10

void sort (int *arr, unsigned int n);
unsigned int get_min_index(int *arr, unsigned int first, unsigned int last);

int main (void)
{
    int arr[len] = {10,9,8,7,6,5,4,3,2,1};
    printf("Original Array:\n\r");
    for(unsigned int i=0; i<len; i++)
        printf("%d, ", arr[i]);
    sort(arr, len/2);   // sort half the array

    printf("\n\rArray half sorted:\n\r");
    for(unsigned int i=0; i<len; i++)
        printf("%d, ", arr[i]);
    
    sort(arr, len);
    printf("\n\rArray fully sorted:\n\r");
    for(unsigned int i=0; i<len; i++)
        printf("%d, ", arr[i]);

    return 0;
}

void sort (int *arr, unsigned int n)
{
    unsigned int index_of_min;
    int temp;
    for(unsigned int fill=0; fill<n; fill++)
    {
        index_of_min = get_min_index(arr, fill, n);
        temp = arr[index_of_min];
        arr[index_of_min] = arr[fill];
        arr[fill] = temp;
    }
}

unsigned int get_min_index(int *arr, unsigned int first, unsigned int last)
{
    unsigned int index = first;
    
    for(unsigned int i = first; i<last; i++)
        if (arr[i] < arr[index])
            index = i;  //update current index
    
    return index;
}
