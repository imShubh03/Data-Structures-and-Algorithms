#include <iostream>
using namespace std;

int sumOfNumbers(int i, int n) {
    if (i > n) return 0;  // Base case: if i exceeds n, return 0
    return i + sumOfNumbers(i + 1, n);  // Recursive call and sum up the values
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    int sum = sumOfNumbers(1, n);  // Start the recursion with i = 1
    cout << "Sum of first " << n << " numbers is: " << sum << endl;
    return 0;
}
