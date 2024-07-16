/*
  *  
 ***  
*****  
*****
 *** 
  *  
*/

#include <iostream>
using namespace std;

void upper(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces before stars
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void lower(int n) {
    for (int i = 1; i < n; i++) {
        // Print leading spaces for each row
        for (int j = 1; j <= i; j++) {
            cout << " ";
        }
        // Print stars for each row
        for (int j = 1; j <= 2 * (n - i) - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void nStarDiamond(int n) {
    upper(n);
    lower(n);
}

int main() {
    int n;
    cout << "Enter the number of rows for the diamond: ";
    cin >> n;
    nStarDiamond(n);
    return 0;
}
