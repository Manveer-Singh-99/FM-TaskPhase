#include <stdio.h>
         
//electricity bill calculation
int main() {
    float units;
    printf("Enter the total electricity usage in units: ");
    scanf("%f", &units);

    float bill = 0.0;

    if (units <= 100) {
        bill = units * 5.0;
    } else if (units <= 300) {
        bill = 100 * 5.0 + (units - 100) * 8.0;
    } else {
        bill = 100 * 5.0 + 200 * 8.0 + (units - 300) * 10.0;
    }

    printf("Total electricity bill: ₹%.2f\n", bill);

    return 0;
}
