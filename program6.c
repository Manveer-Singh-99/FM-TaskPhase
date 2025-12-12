#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//count vowels consonants and scramble string
int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int vowels = 0, consonants = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } 
        else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    srand(time(NULL));

    int len = strlen(str);
    
    if (len > 0) {
        for (int i = 0; i < len; i++) {
            int j = rand() % len;
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }

    printf("Scrambled string: %s\n", str);

    return 0;
}