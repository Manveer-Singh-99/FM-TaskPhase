#include <stdio.h> // Include standard I/O.
#include <ctype.h> // Include ctype for checks.
#include <string.h> // Include string lib.

// --- Task 14: File Statistics ---
// Function definition: Counts chars, words, lines.
int count_file_stats(const char *filename) {
    // Open file in read mode.
    FILE *fp = fopen(filename, "r");
    // Check if open failed.
    if (fp == NULL) {
        // Print error.
        perror("Error opening file");
        // Return error code.
        return -1; 
    }

    // Init counters.
    int char_count = 0, word_count = 0, line_count = 0;
    // Variable for current char.
    char ch;
    // State variable for word tracking.
    int in_word = 0; 

    // Loop reading chars.
    while ((ch = fgetc(fp)) != EOF) {
        // Increment char count.
        char_count++;
        // Check newline.
        if (ch == '\n') line_count++;
        
        // Check whitespace.
        if (isspace(ch)) {
            // Set word state to false.
            in_word = 0;
        } else { // If not whitespace.
            // Check if entering new word.
            if (in_word == 0) {
                // Increment word count.
                word_count++;
                // Set word state to true.
                in_word = 1;
            }
        }
    }
    // Close file.
    fclose(fp);
    
    // Handle case where file has text but no trailing newline.
    if (char_count > 0 && line_count == 0) line_count = 1; 

    // Print header for file stats.
    printf("File Stats for '%s':\n", filename);
    // Print all counts.
    printf("Chars: %d | Words: %d | Lines: %d\n", char_count, word_count, line_count);
    // Return success code.
    return 0;
}

// Main function: Entry point.
int main() {
    // Buffer for filename.
    char filename[100];
    // Buffer for content.
    char content[200];
    
    // Print header.
    printf("--- Task 14 Input ---\n");
    // Prompt filename.
    printf("Enter filename to create (e.g., test.txt): ");
    // Read filename.
    scanf("%s", filename);
    
    // Consume leftover newline from buffer.
    getchar(); 

    // Prompt content.
    printf("Enter content for the file (press Enter to finish):\n");
    // Read content line.
    if (fgets(content, sizeof(content), stdin) != NULL) {
        // Open file for writing.
        FILE *fp = fopen(filename, "w");
        // Check if open succeeded.
        if (fp) {
            // Write content to file.
            fputs(content, fp);
            // Close file.
            fclose(fp);
        } else { // If open failed.
            // Print error.
            perror("Could not create file");
            // Return error code.
            return 1;
        }
    }

    // Call stats function.
    count_file_stats(filename);
    // Return success code.
    return 0;
}