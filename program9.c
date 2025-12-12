#include <stdio.h>
//sum of all elements and diagonals in a 4x4 matrix
int main() {
    int matrix[4][4];
    printf("Enter the elements of the 4x4 matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum += matrix[i][j];
        }
    }

    printf("Sum of all elements: %d\n", sum);

    int diagonal1 = 0, diagonal2 = 0;
    for (int i = 0; i < 4; i++) {
        diagonal1 += matrix[i][i];
        diagonal2 += matrix[i][3 - i];
    }

    printf("Sum of main diagonal: %d\n", diagonal1);
    printf("Sum of secondary diagonal: %d\n", diagonal2);

    return 0;
}
