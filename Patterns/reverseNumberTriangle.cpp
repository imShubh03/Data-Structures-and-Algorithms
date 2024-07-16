/*
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
*/

#include <iostream>
using namespace std;

void nNumberTriangle(int n) {
    // Print a triangle pattern with incremental numbers
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the triangle: ";
    cin >> n;
    nNumberTriangle(n);
    return 0;
}
