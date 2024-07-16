/*

* 
* * 
* * * 
* * * * 
* * * * * 

*/

// n.2forests.cpp

#include <iostream>
using namespace std;

void nForest(int n) {
    // Print a triangle pattern
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the forest: ";
    cin >> n;
    nForest(n);
    return 0;
}
