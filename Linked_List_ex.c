#include <stdio.h>
#include <stdlib.h> // malloc function

// Corrected the struct name to node_to_hotel
struct node_to_hotel {
    int room;
    struct node_to_hotel *next; // Points to the next node
};

int main() {

    // Corrected the struct type to node_to_hotel
    struct node_to_hotel *head = (struct node_to_hotel*)malloc(sizeof(struct node_to_hotel));
    struct node_to_hotel *second = (struct node_to_hotel*)malloc(sizeof(struct node_to_hotel));
    struct node_to_hotel *third = (struct node_to_hotel*)malloc(sizeof(struct node_to_hotel));

    head->room = 1;
    head->next = second;

    second->room = 2;
    second->next = third;

    third->room = 3;
    third->next = NULL; // ends list

    // Traverse linked list
    struct node_to_hotel *current = head;

    while (current != NULL) {
        printf("Room %d\n", current->room);
        current = current->next; // Corrected to 'next' for accessing the next node
    }

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
