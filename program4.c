#include <stdio.h>
#include <string.h>
//password authentication with limited attempts
int main() {
    char password[] = "secret";
    int attempts = 3;

    char enteredPassword[50];

    while (attempts > 0) {
        printf("Enter password: ");
        scanf("%s", enteredPassword);

        if (strcmp(enteredPassword, password) == 0) {
            printf("Login successful!\n");
            return 0;
        } else {
            attempts--;
            printf("Incorrect password. Attempts remaining: %d\n", attempts);
        }
    }

    printf("Login failed. Account locked.\n");

    return 0;
}
