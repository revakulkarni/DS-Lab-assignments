#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "B24CE1134" << endl;
    cout << "Enter number of rounds: ";
    cin >> n;

    int player1[n];
    int player2[n];

    cout << "Enter scores for Player 1\n";
    for (int i = 0; i < n; i++) {
        cout << "Round " << i + 1 << " SCORE: ";
        cin >> player1[i];
    }

    cout << "Enter scores for Player 2\n";
    for (int i = 0; i < n; i++) {
        cout << "Round " << i + 1 << " SCORE: ";
        cin >> player2[i];
    }

    int temp;
    for (int p = 0; p < n; p++) {
        for (int c = 0; c < n - p - 1; c++) {
            if (player1[c] < player1[c + 1]) {
                temp = player1[c];
                player1[c] = player1[c + 1];
                player1[c + 1] = temp;
            }
        }
    }

    for (int p = 0; p < n; p++) {
        for (int c = 0; c < n - p - 1; c++) {
            if (player2[c] < player2[c + 1]) {
                temp = player2[c];
                player2[c] = player2[c + 1];
                player2[c + 1] = temp;
            }
        }
    }

    cout << "\nAfter sorting, Player 1's scores are: ";
    for (int i = 0; i < n; i++) {
        cout << player1[i] << "\t";
    }

    cout << "\nAfter sorting, Player 2's scores are: ";
    for (int i = 0; i < n; i++) {
        cout << player2[i] << "\t";
    }

    if (player1[0] > player2[0]) {
        cout << "\nPlayer 1 is the winner!!";
    } else if (player2[0] > player1[0]) {
        cout << "\nPlayer 2 is the winner!!";
    } else {
        cout << "\n-----It's a tie!";
    }
    return 0;
}
