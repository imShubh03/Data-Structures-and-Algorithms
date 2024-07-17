/*
* * * * * * * *
* * *     * * *
* *         * *
*             *
*             *
* *         * *
* * *     * * *
* * * * * * * *
*/
#include <iostream>
using namespace std;

void symmetry(int n) {
    int iniSp = 0;
    
    // Upper half
    for (int i = 0; i < n; i++) {
        // Stars
        for (int j = 1; j <= n - i; j++) {
            cout << "* ";
        }

        // Spaces
        for (int j = 0; j < iniSp; j++) {
            cout << " ";
        }

        // Stars
        for (int j = 1; j <= n - i; j++) {
            cout << "* ";
        }
        iniSp += 2;
        cout << endl;
    }

    // Lower half
    iniSp = 2 * (n - 1);
    for (int i = 0; i < n; i++) {
        // Stars
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        // Spaces
        for (int j = 0; j < iniSp; j++) {
            cout << " ";
        }

        // Stars
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        iniSp -= 2;
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    symmetry(n);
    return 0;
}
