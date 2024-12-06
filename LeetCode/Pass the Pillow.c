#include <stdio.h>

int passThePillow(int n, int time) {
    // Base case: if time is 0, return the current person (index 0)
    if (time == 0) {
        return 0;
    }

    // If time is greater than 0, the pillow passes to the next person
    return (passThePillow(n, time - 1) + 1) % n;
}

int main() {
    int n, time;

    // Input number of people and time in seconds
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the time in seconds: ");
    scanf("%d", &time);

    // Calculate and display the result
    int result = passThePillow(n, time);
    printf("The person who will have the pillow after %d seconds is: %d\n", time, result);

    return 0;
}
/*recur O(time)
#include <stdio.h>

int passThePillow(int n, int time) {
    // Base case: If no more time to pass, return the current person (person 0 initially)
    if (time == 0) {
        return 0;
    }

    // Recursively pass the pillow
    int nextPerson = passThePillow(n, time - 1) + 1;

    // If we pass the pillow beyond the last person, wrap around to the first person
    if (nextPerson == n) {
        nextPerson = 0;
    }

    return nextPerson;
}

int main() {
    int n, time;

    // Input number of people and time in seconds
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the time in seconds: ");
    scanf("%d", &time);

    // Calculate and display the result
    int result = passThePillow(n, time);
    printf("The person who will have the pillow after %d seconds is: %d\n", time, result);

    return 0;
}
*/