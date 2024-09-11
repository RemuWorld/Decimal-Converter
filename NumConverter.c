#include <stdio.h>
#include <string.h>
#include <ctype.h>  // To use isdigit()

// Convert Decimal to Binary
void binary(int num) 
{
    printf("Binary: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");  // For better reading
    }
    printf("\n");
}

// Convert Decimal to Octal
void octal(int num) 
{
    printf("Octal: %o\n", num);
}

// Convert Decimal to Hexadecimal
void hexadecimal(int num) 
{
    printf("Hexadecimal: %X\n", num);
}

int main() {
    int num;
    char type[4];  // Converter saving char array
    int keepRunning = 1;  // start stop
    char buffer[100];  // Saving fgets (Max 100 letters)

    while (keepRunning) {
        printf("Insert any number\n\n> ");

        // fgets -> buffer -> buffer pointing endPtr
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endPtr;
            
            // Using strtol() read only numbers. Check if last char is num
            num = strtol(buffer, &endPtr, 10);
            
            // No number or none changed then continue
            if (endPtr == buffer || *endPtr != '\n') {
                printf("\nNot a number. Type again\n");
                continue;
            }

            // Check what type of convert user needs
            printf("\nWhat type you want to convert \n1. [bin]\n2. [oct]\n3. [hex]\n\n> ");
            scanf("%s", type);

            // Check if it's in the if statement
            if (strcmp(type, "bin") == 0) {
                binary(num);  // To Binary
            }
            else if (strcmp(type, "oct") == 0) {
                octal(num);  // To Octal
            }
            else if (strcmp(type, "hex") == 0) {
                hexadecimal(num);  // To Hexadecimal
            }
            else {
                printf("ERROR: UNDEFINED FUNCTION\n");
            }

            // Eraser
            while (getchar() != '\n');
        }

        // Check if user want's to continue
        printf("\nContinue? (y/n): ");
        char response;
        scanf(" %c", &response);
        if (response == 'n' || response == 'N') {
            keepRunning = 0;  // End While statement
        }

        // Eraser
        while (getchar() != '\n');
    }

    return 0;
}
