/*

1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

*/


#include <iostream>
using namespace std;

void nTriangle(int n) {
    // Print a right-angled triangle pattern with numbers
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the triangle: ";
    cin >> n;
    nTriangle(n);
    return 0;
}
