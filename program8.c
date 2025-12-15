#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib for malloc.

// --- Task 8: Swap Adjacent Elements ---
// Function definition: Swaps i and i+1 elements.
void swap_adjacent_pointers(int *arr, int n) {
    // Check for invalid size.
    if (n <= 0) return;

    // Loop through array up to second to last element.
    for (int i = 0; i < n - 1; i++) {
        // Save value at current pointer.
        int temp = *(arr + i); 
        // Overwrite current with next value.
        *(arr + i) = *(arr + i + 1); 
        // Overwrite next with saved value.
        *(arr + i + 1) = temp; 
    }
}

// Main function: Entry point.
int main() {
    // Variable for size.
    int n;
    // Print header.
    printf("--- Task 8 Input ---\n");
    // Prompt for size.
    printf("Enter array size: ");
    // Read input.
    scanf("%d", &n);

    // Validate size.
    if (n <= 0) {
        // Print error.
        printf("Invalid size.\n");
        // Return error code.
        return 1;
    }

    // Allocate memory.
    int *arr = malloc(n * sizeof(int));
    // Prompt for data.
    printf("Enter %d integers:\n", n);
    // Loop to read data.
    for (int i = 0; i < n; i++) {
        // Store input.
        scanf("%d", &arr[i]);
    }

    // Call swap function.
    swap_adjacent_pointers(arr, n);

    // Print label.
    printf("Modified Array: ");
    // Loop to print result.
    for (int i = 0; i < n; i++) {
        // Print element.
        printf("%d ", arr[i]);
    }
    // Print newline.
    printf("\n");

    // Free memory.
    free(arr);
    // Return success code.
    return 0;
}
