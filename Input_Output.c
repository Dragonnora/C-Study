#include <stdio.h>
#include <stdlib.h>

// in CodeBlocks, must save .txt file as "all files" type and store it in the same file location as the source file of the code. 

int main()
{
    // Declare a file pointer
    FILE *inputFile;

    int number;

    // Open the file for reading
    inputFile = fopen("Input.txt", "r");

    if (inputFile != NULL) {

        printf("Content:\n");

        while (fscanf(inputFile, "%d", &number) == 1) {
            printf("Number: %d\n", number);  // Corrected the print statement
        }

        fclose(inputFile); // Close the file
    } else {
        printf("Error: Cannot open file.\n");
    }

    return 0;
}
