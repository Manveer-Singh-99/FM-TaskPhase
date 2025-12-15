#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib.
#include <string.h> // Include string lib.
#include <ctype.h> // Include character type lib.
#include <time.h> // Include time lib.

// --- Task 6: Count Vowels and Consonants, Scramble String ---
// Function definition: Analyzes and scrambles string.
void count_vowels_consonants_scramble(char str[]) {
    // Initialize counters.
    int vowels = 0, consonants = 0;
    // Get string length.
    int len = strlen(str);

    // Loop through characters.
    for (int i = 0; i < len; i++) {
        // Convert char to lowercase.
        char ch = tolower(str[i]); 
        // Check if char is alphabet.
        if (isalpha(ch)) { 
            // Check if char is vowel.
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                // Increment vowel count.
                vowels++;
            } else {
                // Increment consonant count.
                consonants++;
            }
        }
    }

    // Print counts.
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);

    // Fisher-Yates shuffle algorithm.
    for (int i = len - 1; i > 0; i--) {
        // Generate random index.
        int j = rand() % (i + 1); 
        // Swap characters.
        char temp = str[i];
        // Assign j to i.
        str[i] = str[j];
        // Assign temp to j.
        str[j] = temp;
    }

    // Print scrambled string.
    printf("Scrambled string: %s\n", str);
}

// Main function: Entry point.
int main() {
    // Seed random number generator.
    srand(time(NULL)); 
    // Buffer for input string.
    char str[100];

    // Print header.
    printf("--- Task 6 Input ---\n");
    // Prompt user.
    printf("Enter a string (max 99 chars): ");
    
    // Read line from input safely.
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove trailing newline char.
        str[strcspn(str, "\n")] = 0;
        // Call processing function.
        count_vowels_consonants_scramble(str);
    }
    
    // Return success code.
    return 0;
}
