#include <iostream>
using namespace std;

int main() {
    cout << "B24CE1134" << endl;
    cout << "Rainfall Data of 4 months for 3 Cities (in mm)" << endl;

    float rainfall[3][4];
    for (int c = 0; c < 3; c++) {
        cout << "\nEnter rainfall for City " << (c + 1) << ":\n";
        for (int m = 0; m < 4; m++) {
            cout << "Enter for Month " << (m + 1) << ": ";
            cin >> rainfall[c][m];
        }
    }
    cout << "\nRainfall Data (in mm):\n";
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "S.No\tCity Name\tMonth1\tMonth2\tMonth3\tMonth4\tAverage\n";
    cout << "------------------------------------------------------------------------------------\n";

    for (int c = 0; c < 3; c++) {
        float sum = 0;
        cout << c + 1 << "\tCity " << c + 1;
        if (c + 1 < 10) cout << "\t\t";
        else cout << "\t";
        for (int m = 0; m < 4; m++) {
            cout << rainfall[c][m] << "\t";
            sum += rainfall[c][m];
        }

        float average = sum / 4;
        cout << average << endl;
    }
    cout << "------------------------------------------------------------------------------------\n";

    return 0;
}
