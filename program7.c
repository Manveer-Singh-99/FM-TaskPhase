#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib for malloc.
#include <limits.h> // Include limits for INT_MIN.

// --- Task 7: Find Second-Largest Element ---
// Function definition: Finds 2nd largest in array.
void find_second_largest(int arr[], int n, int *second_largest) {
    // Check if array has enough elements.
    if (n < 2) {
        // Print error for small array.
        printf("Array needs at least 2 elements.\n");
        // Exit function.
        return;
    }

    // Initialize largest with first element.
    int largest = arr[0];
    // Initialize second largest with minimum integer value.
    int second_largest_val = INT_MIN; 

    // Loop starting from second element.
    for (int i = 1; i < n; i++) {
        // If current is larger than largest.
        if (arr[i] > largest) {
            // Move largest to second largest.
            second_largest_val = largest;
            // Update largest with current.
            largest = arr[i];
        } else if (arr[i] > second_largest_val && arr[i] != largest) { // If between current largest and second largest.
            // Update second largest.
            second_largest_val = arr[i];
        }
    }

    // Store result in output pointer.
    *second_largest = second_largest_val;
}

// Main function: Entry point.
int main() {
    // Variable for size.
    int n;
    // Print header.
    printf("--- Task 7 Input ---\n");
    // Prompt for size.
    printf("Enter array size (>=2): ");
    // Read size and validate.
    if (scanf("%d", &n) != 1 || n < 2) {
        // Print error.
        printf("Invalid size. Must be >= 2.\n");
        // Return error code.
        return 1;
    }

    // Allocate memory for array.
    int *arr = malloc(n * sizeof(int));
    // Prompt for elements.
    printf("Enter %d integers:\n", n);
    // Loop to read input.
    for (int i = 0; i < n; i++) {
        // Store input in array.
        scanf("%d", &arr[i]);
    }

    // Variable for result.
    int result;
    // Call search function.
    find_second_largest(arr, n, &result);
    
    // Check if a valid second largest was found.
    if (result == INT_MIN) {
        // Message for no second largest (e.g. all same numbers).
        printf("No second largest element found (all elements might be equal).\n");
    } else {
        // Print result.
        printf("Second largest element: %d\n", result);
    }

    // Free memory.
    free(arr);
    // Return success code.
    return 0;
}
