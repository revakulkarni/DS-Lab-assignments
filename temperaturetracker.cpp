#include <iostream>
using namespace std;

int main() {
    cout << "B24CE1134" << endl;
    cout << "Daily Temperatures of 3 Cities for 7 Days (in °C)" << endl;

    float temp[3][7];

    for (int c = 0; c < 3; c++) {
        cout << "\nEnter temperatures for City " << (c + 1) << ":\n";
        for (int d = 0; d < 7; d++) {
            cout << "Enter for Day " << (d + 1) << ": ";
            cin >> temp[c][d];
        }
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n";
    cout << "S.No\tCity Name\tDay1\tDay2\tDay3\tDay4\tDay5\tDay6\tDay7\tAverage (Week)\n";
    cout << "---------------------------------------------------------------------------------------------------\n";
    for (int c = 0; c < 3; c++) {
        float sum = 0;
        cout << (c + 1) << "\tCity " << (c + 1);
        if (c + 1 < 10) cout << "\t\t";
        else cout << "\t";

        for (int d = 0; d < 7; d++) {
            cout << temp[c][d] << "\t";
            sum += temp[c][d];
        }

        float averageCity = sum / 7;
        cout << averageCity << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------\n";
    cout << "Average Temp per Day\t";

    for (int d = 0; d < 7; d++) {
        float sum = 0;
        for (int c = 0; c < 3; c++) {
            sum += temp[c][d];
        }
        float avgDay = sum / 3;
        cout << avgDay << "\t";
    }
    cout << endl;

    return 0;
}
