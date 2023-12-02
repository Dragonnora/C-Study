// Function that creates a linked list of nodes based on user input
list_node_t *get_list(void)
{
    int data;
    list_node_t *ansp; // Represents the current node being created

    scanf("%d", &data);

    // If user input equals the sentinel value, end the list
    if (data == SENTINEL_VALUE) {
        ansp = NULL;
    } else {
        // Allocate memory for the current node
        ansp = (list_node_t *)malloc(sizeof(list_node_t));

        // Store data in the current node
        ansp->digit = data;

        // Uses recursion to create the linked list
        ansp->restp = get_list();
    }

    // Return the pointer to the head of the linked list
    return ansp;
}
