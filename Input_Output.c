#include <stdio.h>
#include <stdlib.h>

// in CodeBlocks, must save .txt file as "all files" type and store it in the same file location as the source file of the code. 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declare files
    FILE *inF;
    FILE *outF;

    char c;
    int result = 1;

    // declare pointer to result
    int *ptr_result = &result;

    // open files
    inF = fopen("Input.txt", "r"); // read mode
    outF = fopen("Output.txt", "w"); // write mode

    if (inF != NULL && outF != NULL){

        while (fscanf(inF, " %c", &c) == 1){ // reads individual characters

            if (c >= '0' && c <= '9'){ // checks if character is a digit

                int digit = c - '0'; // converts character to integer

                *ptr_result *= digit; // multiplies result by digit and stores value in pointer

                fprintf(outF, "%d\n\n", *ptr_result); // writes product to output file
            }
        }

    } else printf("Error");

    return 0;
}
