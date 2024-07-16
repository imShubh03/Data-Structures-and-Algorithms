/*
*********
 *******
  *****
   ***
    *
*/
#include <iostream>
using namespace std;

void nStarTriangle(int n) {
    // Print an inverted pyramid pattern with stars
    for(int i = 1; i <= n; i++) {
        // Print leading spaces for each row
        for(int j = 1; j < i; j++) {
            cout << " ";
        }
        // Print stars for each row
        for(int j = 1; j <= 2 * (n - i + 1) - 1; j++) {
            cout << "*";
        }
        for(int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the triangle: ";
    cin >> n;
    nStarTriangle(n);
    return 0;
}
