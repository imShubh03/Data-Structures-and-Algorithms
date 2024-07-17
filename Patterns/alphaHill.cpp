/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
#include <iostream>
using namespace std;

void alphaHill(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces before characters
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print characters
        char ch = 'A';
        int numChars = 2 * i - 1; // Number of characters to print
        int midPoint = numChars / 2;
        for (int j = 0; j < numChars; j++) {
            cout << ch;
            if (j < midPoint) {
                ch++; // Increase character
            } else {
                ch--; // Decrease character
            }
        }

        // Print spaces after characters
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    alphaHill(n);
    return 0;
}
