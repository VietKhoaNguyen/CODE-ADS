#include <stdio.h>

// Function to find the divisors of a number
void find_divisors(int num) {
    printf("Divisors of %d: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to play the Divisor Game
void play_game() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    find_divisors(num);

    int choice;
    printf("Do you want to play again? (1/0): ");
    scanf("%d", &choice);

    if (choice == 1) {
        play_game();
    } else {
        printf("Game over!\n");
    }
}

int main() {
    play_game();
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Function to find the divisors of a number recursively
void find_divisors_recursive(int num, int i) {
    if (i > num) {
        return;
    }
    if (num % i == 0) {
        printf("%d ", i);
    }
    find_divisors_recursive(num, i + 1);
}

// Function to play the Divisor Game recursively
void play_game_recursive() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Divisors of %d: ", num);
    find_divisors_recursive(num, 1);
    printf("\n");

    int choice;
    printf("Do you want to play again? (1/0): ");
    scanf("%d", &choice);

    if (choice == 1) {
        play_game_recursive();
    } else {
        printf("Game over!\n");
    }
}

int main() {
    play_game_recursive();
    return 0;
})*/