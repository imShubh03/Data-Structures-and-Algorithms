#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        if (m < n) return ""; // If s is smaller than t, no valid substring can exist
        
        int minLen = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < m; i++) {
            vector<int> hash(256, 0);
            for (char c : t) hash[c]++; // Frequency count of characters in t

            int count = n; // Count of characters to be matched
            
            for (int j = i; j < m; j++) {
                if (hash[s[j]] > 0) count--;
                hash[s[j]]--;

                // If all characters are matched
                if (count == 0) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        startIndex = i;
                    }
                    break; // No need to consider longer substrings starting from i
                }
            }
        }
        
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        if (m < n) return ""; // If s is smaller than t, no valid substring can exist

        vector<int> hash(256, 0);
        for (char c : t) hash[c]++; // Count frequency of characters in t

        int left = 0, right = 0, count = 0, minLen = INT_MAX, start = -1;

        while (right < m) {
            // Include current character in the window
            if (hash[s[right]] > 0) count++;
            hash[s[right]]--;

            // If all characters of t are matched
            while (count == n) {
                // Update minimum window size
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Shrink the window from the left
                hash[s[left]]++;
                if (hash[s[left]] > 0) count--;
                left++;
            }
            
            // Move the right pointer
            right++;
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};


int main() {
    
    string s, t;
    cin>>s>>t;

    Solution sol;
    string s = sol.minWindow(s, t);
    cout<<s;

    return 0;
}