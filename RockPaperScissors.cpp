#include <iostream>
#include <ctime>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> hands{
    {"rock", 1},
    {"paper", 2},
    {"scissors", 3}
};

string getCompChoice(int compChoice) {
    switch (compChoice) {
    case 1:
        return "rock";
    case 2:
        return "paper";
    case 3:
        return "scissors";
    default:
        return "";
    }
}

int comp() {
    srand(time(NULL));
    int ran = rand() % 3 + 1;
    return ran;
}

bool checkWin(int userChoice, int compChoice) {
    if (userChoice == compChoice) {
        cout << "It's a tie!\n";
        return false;
    }
    if ((userChoice == 1 && compChoice == 3) ||
        (userChoice == 2 && compChoice == 1) ||
        (userChoice == 3 && compChoice == 2)) {
        cout << "You win!\n";
        return true;
    }
    else {
        cout << "You lose!\n";
        return false;
    }
}

int main() {
    string user;
    bool victory = false;

    while (!victory) {
        cout << "Rock-Paper-Scissors: ";
        cin >> user;

        if (hands.find(user) == hands.end()) {
            cout << "Invalid input. Please enter rock, paper, or scissors.\n";
            continue;
        }

        int userChoice = hands[user];
        int compChoice = comp();
        string compChoiceStr = getCompChoice(compChoice);

        cout << "You chose: " << user << endl;
        cout << "Computer chose: " << compChoiceStr << endl;

        victory = checkWin(userChoice, compChoice);
    }

    return 0;
}
