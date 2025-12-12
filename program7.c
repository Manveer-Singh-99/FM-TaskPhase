#include <stdio.h>
//find second largest element in an array using pointers
int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *ptr1 = &arr[0];
    int *ptr2 = &arr[0];

    for (int i = 1; i < n; i++) {
        if (*ptr1 < *ptr2) {
            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }
    }

    int *secondLargestPtr = &arr[1];

    printf("Second largest element: %d\n", *secondLargestPtr);
    return 0;
}
