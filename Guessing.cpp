#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    // Game logic will be added here
    return 0;
}
class Player {
public:
    std::string name;
    std::string avatar;
    int score = 0;

    void createProfile() {
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Choose an avatar: ";
        std::cin >> avatar;
    }

    void showProfile() const {
        std::cout << "Name: " << name << "\nAvatar: " << avatar << "\nScore: " << score << std::endl;
    }
};
class Game {
public:
    int level = 1;
    int maxRange = 50;
    int maxAttempts = 10;
    int number;
    bool hintUsed = false;

    void showRules() const {
        std::cout << "Guess the number between 1 and " << maxRange << ". You have " << maxAttempts << " attempts.\n";
    }

    void setupLevel() {
        number = rand() % maxRange + 1;
        maxAttempts = std::max(10 - level, 3);
        hintUsed = false;
    }

    void playLevel(Player& player) {
        int guess;
        for (int attemptsLeft = maxAttempts; attemptsLeft > 0; --attemptsLeft) {
            std::cout << "Attempt " << maxAttempts - attemptsLeft + 1 << "/" << maxAttempts << ": ";
            std::cin >> guess;
            if (guess == number) {
                std::cout << "Correct! You've guessed the number.\n";
                player.score += (attemptsLeft + 1) * 10;
                return;
            } else if (guess < number) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "Too high! Try again.\n";
            }
        }
        std::cout << "Out of attempts! The number was " << number << ".\n";
    }

    void start(Player& player) {
        while (level <= 5) {
            std::cout << "\nLevel " << level << "\n";
            showRules();
            setupLevel();
            playLevel(player);
            ++level;
        }
    }
};
