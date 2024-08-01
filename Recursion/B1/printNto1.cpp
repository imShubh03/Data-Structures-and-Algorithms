#include <iostream>
using namespace std;

void printNumbers(int i, int n) {
    if (i < 1) return;  // Base case: if i is less than 1, return
    cout << i << " ";   // Print the current number
    printNumbers(i - 1, n);  // Recursive call with i decremented
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    printNumbers(n, n);  // Start the recursion with i = n
    return 0;
}
