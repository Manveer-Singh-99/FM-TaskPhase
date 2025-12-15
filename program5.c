#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib for malloc/free.

// --- Task 5: Remove Duplicates from an Array ---
// Function definition: Returns a new array with unique elements.
int* remove_duplicates(int arr[], int n, int *new_size) {
    // Validate that array size is positive.
    if (n <= 0) return NULL;

    // Allocate temp memory to track unique items found.
    int *temp = malloc(n * sizeof(int)); 
    // Check for allocation failure.
    if (!temp) return NULL;
    
    // Counter for unique elements.
    int j = 0;

    // Iterate through input array.
    for (int i = 0; i < n; i++) {
        // Flag to mark duplicates.
        int is_duplicate = 0;
        // Check current item against temp array.
        for (int k = 0; k < j; k++) {
            // If match found in temp.
            if (arr[i] == temp[k]) {
                // Set flag to true.
                is_duplicate = 1;
                // Stop checking.
                break;
            }
        }
        // If no match found.
        if (!is_duplicate) {
            // Add to temp array and increment counter.
            temp[j++] = arr[i];
        }
    }

    // Update the output size variable.
    *new_size = j;
    // Allocate exact memory for the result.
    int *result = (int *)malloc(sizeof(int) * (*new_size));
    // Check for allocation failure.
    if (result == NULL) {
        // Free temp memory before returning.
        free(temp); 
        // Return NULL indicating error.
        return NULL;
    }

    // Copy data from temp to result.
    for (int i = 0; i < *new_size; i++) {
        // Assignment copy.
        result[i] = temp[i];
    }
    
    // Free the temporary buffer.
    free(temp); 
    // Return the unique array.
    return result;
}

// Main function: Entry point.
int main() {
    // Variable for array size.
    int n;
    
    // Print header.
    printf("--- Task 5 Input ---\n");
    // Prompt for size.
    printf("Enter number of elements: ");
    // Read size and validate it is positive.
    if (scanf("%d", &n) != 1 || n <= 0) {
        // Handle invalid size.
        printf("Invalid size.\n");
        // Return error code.
        return 1;
    }

    // Dynamically allocate memory for user input array.
    int *arr = malloc(n * sizeof(int));
    // Check allocation success.
    if (arr == NULL) {
        // Handle memory error.
        printf("Memory error.\n");
        // Return error code.
        return 1;
    }

    // Prompt for array elements.
    printf("Enter %d integers separated by space:\n", n);
    // Loop to read n integers.
    for (int i = 0; i < n; i++) {
        // Read each integer into array.
        scanf("%d", &arr[i]);
    }

    // Variable to hold new size.
    int new_size;
    // Call function to remove duplicates.
    int *unique_arr = remove_duplicates(arr, n, &new_size);
    
    // Check if result is valid.
    if (unique_arr != NULL) {
        // Print output label.
        printf("Unique array: ");
        // Loop to print unique elements.
        for (int i = 0; i < new_size; i++) {
            // Print individual element.
            printf("%d ", unique_arr[i]);
        }
        // Print newline.
        printf("\n");
        // Free the memory allocated inside the function.
        free(unique_arr); 
    }
    
    // Free the user input array.
    free(arr); 
    // Return success code.
    return 0;
}
