/*
* * * * * 
* * * * 
* * * 
* * 
*
*/

#include <iostream>
using namespace std;

void seeding(int n) {
    // Print a pattern with stars and spaces
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the pattern: ";
    cin >> n;
    seeding(n);
    return 0;
}
