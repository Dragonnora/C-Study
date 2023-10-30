#include <stdio.h>
#include <string.h>

int main() {

  /* first name: Doe 
     middle name: Grace
     last name: Jones */ 

    char fullName[] = "Jones Doe Grace"; // Remove the leading space in the full name
    char firstName[20];
    char lastName[20];
    char middleName[20];

    strncpy(firstName, &fullName[6], 3);

    printf("First Name: %s\n", firstName); // Use %s to print strings

    return 0;
}
