/*
    *
   ***
  *****
 *******
*********
*/
#include <iostream>
using namespace std;

void nStarTriangle(int n) {
    // Print a right-aligned triangle pattern with stars
    for(int i = 1; i <= n; i++) {
        
        // Print spaces before stars
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        
        // Print stars
        for(int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }

        //space        
        for(int j = 1; j <= n - 1; j++) {
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
