#include <stdio.h>
//time conversion from seconds to hours, minutes, seconds
int main() {
    int totalSeconds;
    printf("Enter the total number of seconds: ");
    scanf("%d", &totalSeconds);

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    printf("Hours: %d\n", hours);
    printf("Minutes: %d\n", minutes);
    printf("Seconds: %d\n", seconds);

    return 0;
}
