#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} number_L;

// Function to search for the target value in the linked list
number_L* search(number_L *head, int target) {
    number_L *current = head;

    while (current != NULL) {
        if (current->number == target) {
            return current;  // Target found
        }
        current = current->next;
    }

    return NULL;  // Target not found
}

// Function to print the linked list
void printList(number_L *head) {
    number_L *current = head;

    while (current != NULL) {
        printf("%d, ", current->number);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(number_L *head) {
    number_L *current = head;
    number_L *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    number_L *head = NULL;
    number_L *newNode;
    int inputValue;

    // Build the linked list
    printf("Enter positive integers to create a linked list (enter -1 to end the list):\n");
    while (1) {
        printf("Input: ");
        scanf("%d", &inputValue);
        if (inputValue == -1) {
            break;
        }

        newNode = (number_L *)malloc(sizeof(number_L));
        if (newNode == NULL) {
            printf("Memory allocation failed. Exiting.\n");
            freeList(head);
            return 1;
        }

        newNode->number = inputValue;
        newNode->next = head;
        head = newNode;
    }

    // Print the linked list
    printf("\nLinked List: ");
    printList(head);

    // Search for a target value
    int target;
    printf("\nEnter the target value to search: ");
    scanf("%d", &target);

    number_L *result = search(head, target);

    // Display the result
    if (result != NULL) {
        printf("Target %d found\n", target);
    } else {
        printf("Target not found.\n");
    }

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
