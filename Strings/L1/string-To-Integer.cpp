#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if (n == 0) return 0;

        int i = 0;
        // Remove leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i == n) return 0;

        // Determine the sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long ans = 0;

        // Process digits and calculate the result
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow or underflow
            if (sign == -1 && -1 * ans < INT_MIN) return INT_MIN;
            if (sign == 1 && ans > INT_MAX) return INT_MAX;

            i++;
        }

        return (int)(sign * ans);
    }
};

int main() {

    string s;
    cin >>s;

    Solution sol;
    int ans = sol.myAtoi(s);
    cout<<ans <<endl;

    return 0;
}