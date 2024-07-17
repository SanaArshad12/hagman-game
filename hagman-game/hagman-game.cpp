#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    // Welcoming the user
    string name;
    cout << "What is your name? ";
    getline(cin, name);

    cout << "Hello, " << name << ", Time to play hangman!" << endl;

    // Wait for 1 second
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Start guessing..." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    // Here we set the secret. You can select any word to play with.
    string word = "hangman";

    // Creates a variable with an empty value
    string guesses = "";

    // Determine the number of turns
    int turns = 10;

    // Create a while loop
    // Check if the turns are more than zero
    while (turns > 0) {
        // Make a counter that starts with zero
        int failed = 0;

        // For every character in secret_word
        for (char& char_in_word : word) {
            // See if the character is in the player's guess
            if (guesses.find(char_in_word) != string::npos) {
                // Print out the character
                cout << char_in_word;
            }
            else {
                // If not found, print a dash
                cout << "_";
                // And increase the failed counter with one
                failed++;
            }
        }
        cout << endl;

        // If failed is equal to zero
        if (failed == 0) {
            // Print You Won
            cout << "You won" << endl;
            // Exit the script
            break;
        }

        // Ask the user to guess a character
        char guess;
        cout << "Guess a character: ";
        cin >> guess;

        // Set the player's guess to guesses
        guesses += guess;

        // If the guess is not found in the secret word
        if (word.find(guess) == string::npos) {
            // Turns counter decreases by 1 (now 9)
            turns--;

            // Print wrong
            cout << "Wrong" << endl;

            // How many turns are left
            cout << "You have " << turns << " more guesses" << endl;

            // If the turns are equal to zero
            if (turns == 0) {
                // Print "You Lose"
                cout << "You Lose" << endl;
            }
        }
    }

    return 0;
}
