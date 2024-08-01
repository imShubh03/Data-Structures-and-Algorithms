#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;  // Base case: factorial of 0 or 1 is 1
    return n * factorial(n - 1);  // Recursive call with n decremented
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    int result = factorial(n);
    cout << "Factorial of " << n << " is: " << result << endl;
    return 0;
}
