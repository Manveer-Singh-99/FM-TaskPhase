#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib.

// --- Task 11: Bubble Sort, Selection Sort, Binary Search ---
// Function definition: Sorts array using Bubble Sort.
void bubble_sort(int arr[], int n) {
    // Outer loop for passes.
    for (int i = 0; i < n - 1; i++) {
        // Inner loop for comparisons.
        for (int j = 0; j < n - i - 1; j++) {
            // If current is larger than next.
            if (arr[j] > arr[j + 1]) {
                // Swap them.
                int temp = arr[j];
                // Move next to current.
                arr[j] = arr[j + 1];
                // Move temp to next.
                arr[j + 1] = temp;
            }
        }
    }
}

// Function definition: Performs Binary Search on sorted array.
int binary_search(int arr[], int n, int target) {
    // Init bounds.
    int low = 0, high = n - 1;
    // Loop while range is valid.
    while (low <= high) {
        // Calculate mid safely.
        int mid = low + (high - low) / 2; 
        // Check match.
        if (arr[mid] == target) {
            // Return index.
            return mid; 
        } else if (arr[mid] < target) { // If target is larger.
            // Move low up.
            low = mid + 1;
        } else { // If target is smaller.
            // Move high down.
            high = mid - 1;
        }
    }
    // Return not found.
    return -1; 
}

// Main function: Entry point.
int main() {
    // Variables for input.
    int n, target;
    
    // Print header.
    printf("--- Task 11 Input ---\n");
    // Prompt size.
    printf("Enter size of array: ");
    // Read size.
    scanf("%d", &n);
    
    // Validate size.
    if (n <= 0) return 1;

    // Allocate memory.
    int *arr = malloc(n * sizeof(int));
    // Prompt data.
    printf("Enter %d numbers:\n", n);
    // Loop read data.
    for (int i = 0; i < n; i++) {
        // Store in array.
        scanf("%d", &arr[i]);
    }

    // Sort array automatically.
    bubble_sort(arr, n);
    // Print label.
    printf("Array sorted automatically for Binary Search: ");
    // Loop print sorted.
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    // Print newline.
    printf("\n");

    // Prompt search target.
    printf("Enter number to search for: ");
    // Read target.
    scanf("%d", &target);

    // Perform search.
    int index = binary_search(arr, n, target);
    // Check result.
    if (index != -1) {
        // Print found index.
        printf("Found %d at index %d (sorted).\n", target, index);
    } else {
        // Print not found.
        printf("%d not found.\n", target);
    }

    // Free memory.
    free(arr);
    // Return success code.
    return 0;
}