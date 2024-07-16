/*
*
**
***
****
***
**
*
*/

#include <iostream>
using namespace std;

void nStarTriangle(int n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = i;
        if (i > n) {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the triangle: ";
    cin >> n;
    nStarTriangle(n);
    return 0;
}
