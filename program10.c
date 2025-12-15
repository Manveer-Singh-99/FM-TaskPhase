#include <stdio.h> // Include standard I/O.

// --- Task 10: Rotate Matrix by 90 Degrees Clockwise ---
// Function definition: Rotates matrix using temp buffer.
void rotate_matrix(int matrix[4][4]) {
    // Temp matrix to store result.
    int temp[4][4];

    // Loop rows.
    for (int i = 0; i < 4; i++) {
        // Loop columns.
        for (int j = 0; j < 4; j++) {
            // Map original coords to rotated coords.
            temp[j][3 - i] = matrix[i][j]; 
        }
    }

    // Print header.
    printf("Rotated matrix (90 degrees clockwise):\n");
    // Loop rows.
    for (int i = 0; i < 4; i++) {
        // Loop columns.
        for (int j = 0; j < 4; j++) {
            // Copy temp back to original.
            matrix[i][j] = temp[i][j];
            // Print element.
            printf("%4d ", matrix[i][j]);
        }
        // Print newline.
        printf("\n");
    }
}

// Main function: Entry point.
int main() {
    // Declare matrix.
    int matrix[4][4];
    
    // Print header.
    printf("--- Task 10 Input ---\n");
    // Prompt user.
    printf("Enter 16 integers for a 4x4 matrix:\n");
    
    // Loop rows.
    for (int i = 0; i < 4; i++) {
        // Prompt specific row.
        printf("Row %d: ", i + 1);
        // Loop columns.
        for (int j = 0; j < 4; j++) {
            // Read input.
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call rotate function.
    rotate_matrix(matrix);
    // Return success code.
    return 0;
}
