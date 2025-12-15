#include <stdio.h> // Include standard I/O.
#include <string.h> // Include string library for strcmp/strcspn.

// --- Task 4: Simple Login System ---
// Function definition: Simulates login flow.
void simple_login(char username[]) {
    // Define the correct hardcoded password.
    char correct_password[] = "password";
    // Set maximum login attempts.
    int attempts = 3;

    // Greet the user by name.
    printf("Welcome, %s! Please log in.\n", username);

    // Loop for the allowed number of attempts.
    for (int i = 0; i < attempts; i++) {
        // Prompt for password.
        printf("Enter password: ");
        // Buffer to hold user input.
        char entered_password[50]; 
        
        // Securely read password input; exit if reading fails.
        if (fgets(entered_password, sizeof(entered_password), stdin) == NULL) return;

        // Remove the newline character that fgets captures.
        entered_password[strcspn(entered_password, "\n")] = 0;

        // Compare input with correct password.
        if (strcmp(entered_password, correct_password) == 0) {
            // If match found, print success.
            printf("Login successful!\n");
            // Exit function immediately.
            return; 
        } else { // If match fails.
            // Print error and remaining attempts.
            printf("Incorrect. %d attempts remaining.\n", attempts - i - 1);
        }
    }

    // If loop finishes, attempts are exhausted.
    printf("Access Denied.\n");
}

// Main function: Entry point.
int main() {
    // Buffer for username input.
    char username[50];
    
    // Print header.
    printf("--- Task 4 Input ---\n");
    // Prompt for username.
    printf("Enter username: ");
    
    // Read username securely from stdin.
    if (fgets(username, sizeof(username), stdin) != NULL) {
        // Clean newline from username input.
        username[strcspn(username, "\n")] = 0;
        // Call login function.
        simple_login(username);
    }
    
    // Return success code.
    return 0;
}
