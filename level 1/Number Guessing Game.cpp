#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Seed the random number generator ONCE
    srand(time(0));

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y')
    {
        cout << "========================" << endl;
        cout << "     GUESS THE NUMBER " << endl;
        cout << "========================" << endl;

int randomNumber, guess, attempts = 0, maxAttempts;

        cout << "Choose difficulty level: " << endl;

cout << "1. 🟢 Easy       (1-50)     - 6 attempts" << endl;
cout << "2. 🟡 Medium     (1-100)    - 7 attempts" << endl;
cout << "3. 🔴 Hard       (1-500)    - 12 attempts" << endl;
cout << "4. 💀 Impossible (1-1000)   - 12 attempts" << endl;
        int difficulty;
        cin >> difficulty;

     switch (difficulty)
{
    case 1:
        randomNumber = rand() % 50 + 1;
        maxAttempts = 6;
        break;

    case 2:
        randomNumber = rand() % 100 + 1;
        maxAttempts = 7;
        break;

    case 3:
        randomNumber = rand() % 500 + 1;
        maxAttempts = 12;
        break;

    case 4:
        randomNumber = rand() % 1000 + 1;
        maxAttempts = 12;
        break;

    default:
        cout << "Invalid choice. Defaulting to Medium difficulty." << endl;
        difficulty = 2;
        randomNumber = rand() % 100 + 1;
        maxAttempts = 7;
        break;
}

        cout << "I have selected a number. Try to guess it!" << endl;

        do
        {
            cout << "Enter your guess: ";
            cin >> guess;

            attempts++;

            if (guess < randomNumber)
            {
                cout << "Too low! Try again." << endl;
            }
            else if (guess > randomNumber)
            {
                cout << "Too high! Try again." << endl;
            }
            else
            {
                cout << "Congratulations! You guessed the number!" << endl;
            }

        } while (guess != randomNumber && attempts < maxAttempts);

        cout << "=========================" << endl;
        cout << "       YOUR SCORE        " << endl;
        cout << "=========================" << endl;

        cout << "Difficulty Level: " << difficulty << endl;
        cout << "Number of Attempts Used: " << attempts << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

while (playAgain != 'y' && playAgain != 'Y' &&
       playAgain != 'n' && playAgain != 'N')
{
    cout << "Invalid input! Please enter y or n: ";
    cin >> playAgain;
}
    }

    cout << "Thank you for playing! Goodbye!" << endl;

    return 0;
}