#include <stdio.h> // Include standard input/output library.

// --- Task 13: Pyramid Star Pattern ---
// Function definition: Prints a centered pyramid of stars based on row count.
void star_pattern(int n) {
    // Outer loop: Iterate through each row from 1 to n.
    for (int i = 1; i <= n; i++) {
        // Inner loop 1: Print leading spaces for alignment.
        // Number of spaces is total rows minus current row index (n - i).
        // This pushes the top rows further to the right to center them.
        for (int j = 1; j <= n - i; j++) {
            // Print a single space character.
            printf(" ");
        }
        
        // Inner loop 2: Print stars for the current row.
        // Runs 'i' times, printing a star and a space for each iteration.
        for (int k = 1; k <= i; k++) {
            // Print star followed by a space ("* ") to form the spread-out pyramid shape.
            printf("* ");
        }
        
        // Print a newline character to move to the beginning of the next row.
        printf("\n");
    }
}

// Main function: The entry point of the program.
int main() {
    // Declare an integer variable to hold the user's input for rows.
    int n;

    // Print a descriptive header for the user.
    printf("--- Task 13 Input ---\n");
    // Prompt the user to enter the desired number of rows.
    printf("Enter number of rows: ");

    // Read an integer from standard input (keyboard) into variable 'n'.
    // Check if scanf successfully read exactly 1 item.
    if (scanf("%d", &n) != 1) {
        // If reading failed (e.g. non-integer input), print an error message.
        printf("Invalid input.\n");
        // Return error code 1 to the operating system.
        return 1;
    }

    // Input validation: Ensure the number of rows is positive.
    if (n <= 0) {
        // If n is zero or negative, print an error message.
        printf("Number of rows must be positive.\n");
        // Return error code 1.
        return 1;
    }

    // Call the star_pattern function passing the user's input.
    star_pattern(n);

    // Return 0 to indicate successful program termination.
    return 0;
}