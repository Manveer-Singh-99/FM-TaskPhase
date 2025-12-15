#include <stdio.h> // Include the standard input/output library for printing and reading data.

// --- Task 1: Even/Odd Sum and Prime/Composite ---
// Function definition: Takes three integers to perform parity and primality checks.
void even_odd_prime_composite(int num1, int num2, int num3) {
    // Calculate the total sum of the three input integers.
    int sum = num1 + num2 + num3; 
    
    // Check if the sum is even by looking for a remainder of 0 when divided by 2.
    if (sum % 2 == 0) {
        // If the remainder is 0, print that the sum is even.
        printf("The sum (%d) is even.\n", sum);
    } else { // If the remainder is not 0.
        // Print that the sum is odd.
        printf("The sum (%d) is odd.\n", sum);
    }

    // Safety check: Ensure the numbers are non-negative before checking prime status.
    if (num1 < 0 || num2 < 0 || num3 < 0) {
        // Print an error message if any input is negative.
        printf("Please enter non-negative integers for the prime check.\n");
        // Exit the function early as valid prime checks cannot be done.
        return;
    }

    // Check edge case: Numbers 0 and 1 are mathematically neither prime nor composite.
    if (num1 <= 1) { 
        // Print the result for this specific edge case.
        printf("%d is neither prime nor composite.\n", num1);
    } else { // For numbers greater than 1.
        // Initialize a flag to true (1), assuming the number is prime until proven otherwise.
        int is_prime = 1; 
        
        // Loop from 2 up to the square root of num1 to find any divisors.
        for (int i = 2; i * i <= num1; i++) {
            // Check if num1 is perfectly divisible by the current iterator 'i'.
            if (num1 % i == 0) {
                // If divisible, it is not prime; set the flag to false (0).
                is_prime = 0; 
                // Break the loop immediately since we found a divisor.
                break;      
            }
        }
        
        // Check the status of the flag after the loop.
        if (is_prime) {
            // If the flag is still 1, print that the number is prime.
            printf("%d is prime.\n", num1);
        } else { // If the flag is 0.
            // Print that the number is composite.
            printf("%d is composite.\n", num1);
        }
    }
}

// Main function: The entry point of the program.
int main() {
    // Declare three integer variables to store user input.
    int n1, n2, n3;
    
    // Print a header to indicate which task is running.
    printf("--- Task 1 Input ---\n");
    // Prompt the user to enter data.
    printf("Enter three integers separated by spaces: ");
    
    // Read three integers from the standard input (keyboard) and store them.
    // Also check if scanf successfully read exactly 3 items.
    if (scanf("%d %d %d", &n1, &n2, &n3) != 3) {
        // If reading failed (e.g., user entered text), print an error.
        printf("Invalid input. Please enter numbers only.\n");
        // Return error code 1 to the operating system.
        return 1;
    }

    // Call the processing function with the user's inputs.
    even_odd_prime_composite(n1, n2, n3);
    // Return 0 to indicate successful program execution.
    return 0;
}
