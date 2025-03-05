#include <iostream>
#include <cstdlib>
#include <ctime>

int generate_random_number() {
    return rand() % 100 + 1;  // Generates a number between 1 and 100
}

void play_game() {
    int random_number = generate_random_number();
    int guess;
    int attempts = 0;  // Initialize attempts

    std::cout << "🎯 Welcome to the Number Guessing Game! \n";
    std::cout << "I have chosen a number between **1 and 100**. Can you guess it? \n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < random_number) {
            std::cout << "📉 Too low! Try again. \n";
        } else if (guess > random_number) {
            std::cout << "📈 Too high! Try again. \n";
        } else {
            std::cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts. \n";
        }
    } while (guess != random_number);
}

int main() {
    srand(time(0));
    play_game();
    return 0;
}
