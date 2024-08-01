#include <iostream>
using namespace std;

void printNumbers(int i, int n) {
    if (i > n) return;  // Base case: if i exceeds n, return
    cout << i << " ";   // Print the current number
    printNumbers(i + 1, n);  // Recursive call with i incremented
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    printNumbers(1, n);  // Start the recursion with i = 1
    return 0;
}
