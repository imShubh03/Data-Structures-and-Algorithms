/*
1 1 1 1
2 2 2
3 3
4
*/

#include <iostream>
using namespace std;

void nNumberTriangle(int n) {
    // Print a triangle pattern with incremental numbers
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout << i << " ";
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
