#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    char data;
    struct Node* next;
};

// Function prototypes
void addNode(struct Node**, char);
void removeNode(struct Node**, char);
void displayList(struct Node*);
void freeList(struct Node*);

int main() {
    // Initialize head of the linked list
    struct Node* head = NULL;
    char choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Add a node\n");
        printf("2. Remove a node\n");
        printf("3. Display nodes\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': // Add node to list
                printf("Enter a character to add: ");
                scanf(" %c", &value);
                addNode(&head, value);
                break;
            case '2': // Remove node from list
                printf("Enter a character to remove: ");
                scanf(" %c", &value);
                removeNode(&head, value);
                break;
            case '3': // Print list
                displayList(head);
                break;
            case '4': // Quit program
                printf("Quitting program.\n");
                break;
            default: // Input verification 
                printf("Invalid choice. Please enter a valid option.\n");
        }
        // Until user selects 'Quit'
    } while (choice != '4');

    // Free allocated memory for the linked list
    freeList(head);

    return 0;
}

// Function to add a node to the ordered list
void addNode(struct Node** head, char value) {
    
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert the new node into the ordered list
    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // print the updated list
    printf("List: ");
    displayList(*head);
}

// Function to remove a node from the list
void removeNode(struct Node** head, char value) {
    // Traverse the list to find the node to be removed
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        printf("Character not found in the list.\n");
        return;
    }

    // Update pointers to remove the node from the list
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    // Free the memory of the removed node
    free(temp);

    // Print the updated list
    printf("List: ");
    displayList(*head);
}

// Function to display the current list
void displayList(struct Node* head) {
    // Traverse the list and print each node's data
    struct Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the allocated memory for the linked list
void freeList(struct Node* head) {
    // Traverse the list and free the memory for each node
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}
