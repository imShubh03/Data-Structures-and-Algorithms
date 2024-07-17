/*
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
*/

#include <iostream>
using namespace std;

void nNumberTriangle(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num += 1;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    nNumberTriangle(n);
    return 0;
}
