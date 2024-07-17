/*
1      1
12    21
123  321
12344321
*/

#include <iostream>
using namespace std;

void numberCrown(int n) {
    int space = 2 * (n - 1);

    for (int i = 1; i <= n; i++) {
        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Print spaces
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }

        // Print decreasing numbers
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
        space -= 2; // Decrease space count after each row
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    numberCrown(n);
    return 0;
}
