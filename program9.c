#include <stdio.h> // Include standard I/O.

// --- Task 9: 4x4 Matrix Operations ---
// Function definition: Calculates sums and diagonals.
void matrix_operations(int matrix[4][4]) {
    // Print header.
    printf("\nMatrix entered:\n");
    // Loop rows.
    for (int i = 0; i < 4; i++) {
        // Loop columns.
        for (int j = 0; j < 4; j++) {
            // Print element formatted.
            printf("%4d ", matrix[i][j]);
        }
        // Newline for row.
        printf("\n");
    }

    // Init sum variable.
    int sum_all = 0;
    // Loop rows.
    for (int i = 0; i < 4; i++) {
        // Loop columns.
        for (int j = 0; j < 4; j++) {
            // Add element to sum.
            sum_all += matrix[i][j];
        }
    }
    // Print total sum.
    printf("Sum of all elements: %d\n", sum_all);

    // Init diagonal sum.
    int sum_diagonals = 0;
    // Loop for diagonals.
    for (int i = 0; i < 4; i++) {
        // Add main diagonal element.
        sum_diagonals += matrix[i][i]; 
        // Add secondary diagonal element.
        sum_diagonals += matrix[i][3 - i]; 
    }
    // Print diagonal sum.
    printf("Sum of both diagonals: %d\n", sum_diagonals);
}

// Main function: Entry point.
int main() {
    // Declare 4x4 matrix.
    int matrix[4][4];
    
    // Print header.
    printf("--- Task 9 Input ---\n");
    // Prompt user.
    printf("Enter 16 integers for a 4x4 matrix (row by row):\n");
    
    // Loop for input rows.
    for (int i = 0; i < 4; i++) {
        // Prompt for specific row.
        printf("Row %d (4 nums): ", i + 1);
        // Loop for input columns.
        for (int j = 0; j < 4; j++) {
            // Read integer and check validity.
            if (scanf("%d", &matrix[i][j]) != 1) {
                // Print error.
                printf("Invalid input.\n");
                // Return error code.
                return 1;
            }
        }
    }

    // Call operations function.
    matrix_operations(matrix);
    // Return success code.
    return 0;
}
