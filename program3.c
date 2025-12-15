#include <stdio.h> // Include standard I/O library.

// --- Task 3: Calculate Electricity Bills ---
// Function definition: Calculates bill based on usage tiers.
float calculate_electricity_bill(int units) {
    // Validation: Check for negative units.
    if (units < 0) {
        // Print error message.
        printf("Error: Units cannot be negative.\n");
        // Return -1.0 to signal an error state to the caller.
        return -1.0; 
    }

    // Initialize the bill variable to 0.0.
    float bill = 0.0;

    // Tier 1: Check if usage is 100 units or less.
    if (units <= 100) {
        // Calculate cost: units * rate of 5.0.
        bill = units * 5.0; 
    } else if (units <= 300) { // Tier 2: Check if usage is between 101 and 300.
        // Calculate: First 100 at 5.0 + remaining at 8.0.
        bill = 100 * 5.0 + (units - 100) * 8.0; 
    } else { // Tier 3: Usage above 300.
        // Calculate: First 100 at 5.0 + next 200 at 8.0 + rest at 10.0.
        bill = 100 * 5.0 + 200 * 8.0 + (units - 300) * 10.0; 
    }

    // Return the calculated bill amount.
    return bill;
}

// Main function: Entry point.
int main() {
    // Declare variable for input units.
    int units;
    
    // Print header.
    printf("--- Task 3 Input ---\n");
    // Prompt user.
    printf("Enter electricity units consumed: ");
    
    // Read integer input and check for validity.
    if (scanf("%d", &units) != 1) {
        // Error handling for non-integer input.
        printf("Invalid input.\n");
        // Return error code.
        return 1;
    }

    // Call calculation function and store result.
    float result = calculate_electricity_bill(units);
    
    // Check if result is valid (non-negative).
    if (result >= 0) {
        // Print the formatted bill amount.
        printf("Total Bill: $%.2f\n", result);
    }
    
    // Return success code.
    return 0;
}
