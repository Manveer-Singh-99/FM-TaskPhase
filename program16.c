#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib.
#include <string.h> // Include string lib.

// --- Task 16: String Compression ---
// Function definition: Compresses string RLE style.
char* compress_string(char *str) {
    // Check for empty or null string.
    if (str == NULL || strlen(str) == 0) return str;

    // Get length.
    int len = strlen(str);
    // Allocate max potential memory needed.
    char *compressed_str = malloc(len * 2 + 1); 
    // Check allocation.
    if (compressed_str == NULL) return NULL;

    // Initialize string terminator.
    compressed_str[0] = '\0';
    
    // Loop through input string.
    for (int i = 0; i < len; i++) {
        // Init counter.
        int count = 1;
        // Inner loop checks for repeats.
        while (i + 1 < len && str[i] == str[i + 1]) {
            // Increment count.
            count++;
            // Increment index.
            i++;
        }

        // Get current length of result.
        int curr_len = strlen(compressed_str);
        // Append character.
        compressed_str[curr_len] = str[i];
        // Null terminate.
        compressed_str[curr_len + 1] = '\0';

        // If run length > 1.
        if (count > 1) {
            // Buffer for number string.
            char count_str[10];
            // Convert count to string.
            sprintf(count_str, "%d", count);
            // Append number string.
            strcat(compressed_str, count_str);
        }
    }
    // Return result pointer.
    return compressed_str;
}

// Main function: Entry point.
int main() {
    // Buffer for input.
    char str[100];
    // Print header.
    printf("--- Task 16 Input ---\n");
    // Prompt user.
    printf("Enter string to compress (e.g. aaabbc): ");
    
    // Read string from input.
    scanf("%s", str); 

    // Call compression function.
    char *result = compress_string(str);
    // Check if result is valid.
    if (result != NULL) {
        // Print original.
        printf("Original: %s\n", str);
        // Print compressed.
        printf("Compressed: %s\n", result);
        
        // Free result if it was dynamically allocated.
        if (result != str) free(result);
    }
    // Return success code.
    return 0;
}