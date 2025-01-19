#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.size();
        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }

            // Even-length palindromes
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;

    string ans = sol.longestPalindrome(s);
    cout << ans;

    return 0;
}
