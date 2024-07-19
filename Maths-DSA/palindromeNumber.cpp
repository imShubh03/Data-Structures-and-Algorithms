#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int revNum = 0;
        int temp = x;
        while (x) {
            int lastDigit = x % 10;
            revNum = revNum * 10 + lastDigit;
            x = x / 10;
        }

        return revNum == temp;
    }
};

int main() {
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    Solution sol;
    bool result = sol.isPalindrome(x);
    if (result) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }

    return 0;
}
