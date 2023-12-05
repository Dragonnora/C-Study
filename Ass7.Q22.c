#include <stdio.h>
#include <stdlib.h>

void userInput(int *dynamicArray, int size) {
    for (int i = 0; i < size; ++i) {
        printf("input: ");
        scanf("%d", &dynamicArray[i]);
    }
}

void displayValues(const int *dynamicArray, int size) {
    printf("Entered values:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");
}

int main() {
    int arraySize;

    // Allocating memory using malloc
    printf("Enter the size of the array (using malloc): ");
    scanf("%d", &arraySize);

    int *valuesMalloc = (int*)malloc(arraySize * sizeof(int));
    if (valuesMalloc == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Input for malloc:\n");
    userInput(valuesMalloc, arraySize);
    displayValues(valuesMalloc, arraySize);

    // Freeing memory allocated with malloc
    free(valuesMalloc);

    // Allocating memory using calloc
    printf("\nEnter the size of the array (using calloc): ");
    scanf("%d", &arraySize);

    int *valuesCalloc = (int*)calloc(arraySize, sizeof(int));
    if (valuesCalloc == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Input for calloc:\n");
    userInput(valuesCalloc, arraySize);
    displayValues(valuesCalloc, arraySize);

    // Freeing memory allocated with calloc
    free(valuesCalloc);

    return 0;
}
