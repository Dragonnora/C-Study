#include <stdio.h>
#include <stdlib.h>

// Structure for student information
typedef struct Student_Info {
    char firstName[50];
    char lastName[50];
    int ID;
    double grade;
    struct Student_Info* link;
} student;

// Function to add a test paper to the stack
void push(student** top) {
    student* newStudent = (student*)malloc(sizeof(student));

    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter student first name: ");
    scanf("%s", newStudent->firstName);
    printf("Enter student last name: ");
    scanf("%s", newStudent->lastName);
    printf("Enter student ID: ");
    scanf("%d", &(newStudent->ID));
    printf("Enter student grade: ");
    scanf("%lf", &(newStudent->grade));

    newStudent->link = *top;
    *top = newStudent;

    printf("Test paper added to the stack.\n");
}

// Function to remove a test paper from the stack
void pop(student** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot remove test paper.\n");
        return;
    }

    student* temp = *top;
    *top = (*top)->link;
    free(temp);

    printf("Test paper removed from the stack.\n");
}

// Function to print test papers from top to bottom
void printStack(student* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Test papers on the stack (from top to bottom):\n");

    while (top != NULL) {
        printf("Name: %s %s, ID: %d, Grade: %.2lf\n", top->firstName, top->lastName, top->ID, top->grade);
        top = top->link;
    }
}

int main() {
    student* top = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add test paper to stack\n");
        printf("2. Remove test paper from stack\n");
        printf("3. Print test papers (from top to bottom)\n");
        printf("4. Leave your office (exit program)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printStack(top);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free memory before exiting
    while (top != NULL) {
        pop(&top);
    }

    return 0;
}
