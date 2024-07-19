#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while (x > 0) {
            int id = x % 10;
            revNum = (revNum * 10) + id;
            x = x / 10;
        }
        return revNum;
    }
};
*/

//LEETCODE : 7
class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while (x) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        return int(rev);
    }
};

int main() {
    int x;
    cout << "Enter a positive integer: ";
    cin >> x;
    Solution sol;
    int result = sol.reverse(x);
    cout << "Reversed number: " << result << endl;

    return 0;
}
