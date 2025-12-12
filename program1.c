#include <stdio.h>
#include <stdbool.h>
//sum even odd prime composite
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num1, num2, num3;
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;

    printf("Sum: %d\n", sum);

    if (sum % 2 == 0) {
        printf("The sum is even.\n");
    } else {
        printf("The sum is odd.\n");
    }

    if (isPrime(sum)) {
        printf("The sum is prime.\n");
    } else {
        printf("The sum is composite.\n");
    }

    return 0;
}
