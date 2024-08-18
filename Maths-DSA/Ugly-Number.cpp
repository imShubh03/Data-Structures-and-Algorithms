/*
An ugly number is a special type of number that can only be made by multiplying the numbers 2, 3, and 5 together. You start with the number 1, which is considered the first ugly number.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n == 1) return true;
        if(n < 1) return false;

        if(n % 2 == 0) {
            return isUgly(n / 2);
        }
        if(n % 3 == 0) {
            return isUgly(n / 3);
        }
        if(n % 5 == 0) {
            return isUgly(n / 5);
        }
        return false;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter a number to check if it is an ugly number: ";
    cin >> n;

    if (solution.isUgly(n)) {
        cout << n << " is an ugly number." << endl;
    } else {
        cout << n << " is not an ugly number." << endl;
    }

    return 0;
}
