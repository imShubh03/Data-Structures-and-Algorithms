/*
A 
A B 
A B C 
A B C D 
A B C D E 
*/
#include <iostream>
using namespace std;

void nLetterTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    nLetterTriangle(n);
    return 0;
}
