#include <stdio.h> // Include standard I/O.

// --- Task 15: Recursive Fibonacci ---
// Function definition: Calculates Fibonacci number recursively.
int fibonacci(int n) {
    // Base case: return n for 0 and 1.
    if (n <= 1) return n;
    // Recursive case: sum of previous two.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Main function: Entry point.
int main() {
    // Variable for n.
    int n;
    // Print header.
    printf("--- Task 15 Input ---\n");
    // Prompt user.
    printf("Enter n to find the nth Fibonacci number: ");
    
    // Read input and validate non-negative.
    if (scanf("%d", &n) != 1 || n < 0) {
        // Print error.
        printf("Please enter a positive integer.\n");
        // Return error code.
        return 1;
    }

    // Call function and print result.
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    // Return success code.
    return 0;
}