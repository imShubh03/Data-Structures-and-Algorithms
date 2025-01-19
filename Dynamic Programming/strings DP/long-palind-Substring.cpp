#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        if(i >= j) return true;

        if(s[i] == s[j]) {
            return isPalindrome(s, i+1, j-1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int start = 0;
        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                if(isPalindrome(s, i, j) == true){
                    int currlen = j - i +1;
                    if(currlen > maxLen){
                        maxLen = currlen;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
*/

class Solution {
public:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        // Base cases
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j]; // Return cached result
        
        // Check palindrome condition and recurse
        if (s[i] == s[j]) {
            dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
        } else {
            dp[i][j] = false;
        }
        
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        int maxLen = 0;
        int start = 0;

        // Iterate over all possible substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j, dp)) {
                    int currLen = j - i + 1;
                    if (currLen > maxLen) {
                        maxLen = currLen;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {

    string s;
    cin>>s;

    Solution sol;

    string ans = sol.longestPalindrome(s);
    cout<<ans;

    return 0;
}