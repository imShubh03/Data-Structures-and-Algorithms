#include <iostream>
#include <cmath>
using namespace std;

bool checkArmstrong(int n) {
    int temp = n;
    int cntDigits = 0;
    int copy = n;

    // Calculate the number of digits
    while (copy > 0) {
        cntDigits++;
        copy /= 10;
    }

    int sum = 0;
    copy = n; // Reset copy to original number

    // Calculate the sum of each digit raised to the power of cntDigits
    while (copy > 0) {
        int digit = copy % 10;
        sum = sum + pow(digit, cntDigits);
        copy = copy / 10;
    }

    return sum == temp;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    bool result = checkArmstrong(n);
    if (result) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }

    return 0;
}
