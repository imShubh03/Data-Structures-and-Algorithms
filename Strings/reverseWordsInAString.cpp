#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string str) {
        int i = str.length() - 1;
        string ans = "";
        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && str[i] == ' ') {
                i--;
            }

            if (i < 0) break;

            int j = i;

            // Skip non-spaces (i.e., characters of a word)
            while (i >= 0 && str[i] != ' ') {
                i--;
            }

            if (!ans.empty()) {
                ans += " ";
            }
            ans += str.substr(i + 1, j - i);
        }
        return ans;
    }
};

int main() {
    string s = " the sky is blue ";

    Solution sol;

    cout << "the output: " << sol.reverseWords(s) << endl;

    return 0;
}
