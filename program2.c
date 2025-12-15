#include <stdio.h> // Include standard I/O library.

// --- Task 2: Seconds to Hours, Minutes, Seconds ---
// Function definition: Converts total seconds into H:M:S format.
void seconds_to_hms(int seconds) {
    // Validation: Check if the input is negative.
    if (seconds < 0) {
        // Print error message for invalid time.
        printf("Please enter a non-negative number of seconds.\n");
        // Exit the function early.
        return;
    }

    // Calculate total hours by integer division (seconds / 3600).
    int hours = seconds / 3600; 
    // Update 'seconds' to be the remainder after extracting hours.
    seconds %= 3600;             
    // Calculate minutes by dividing the remaining seconds by 60.
    int minutes = seconds / 60;  
    // Calculate the final remaining seconds using modulo 60.
    int remaining_seconds = seconds % 60; 

    // Print the formatted time string.
    printf("Result: %d hours, %d minutes, and %d seconds.\n", hours, minutes, remaining_seconds);
}

// Main function: Entry point.
int main() {
    // Declare variable to store user input.
    int seconds;
    
    // Print task header.
    printf("--- Task 2 Input ---\n");
    // Prompt user for seconds.
    printf("Enter total seconds: ");
    
    // Read one integer from keyboard and validate success.
    if (scanf("%d", &seconds) != 1) {
        // Handle invalid input.
        printf("Invalid input.\n");
        // Return error code.
        return 1;
    }

    // Call logic function with user input.
    seconds_to_hms(seconds);
    // Return success code.
    return 0;
}
