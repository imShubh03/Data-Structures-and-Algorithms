#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            int hash[26] = {0};
            int maxfreq = 0;

            for (int j = i; j < n; j++) {
                hash[s[j] - 'A']++;
                maxfreq = max(maxfreq, hash[s[j] - 'A']);
                int nofchanges = (j - i + 1) - maxfreq;

                if (nofchanges <= k) {
                    maxlen = max(maxlen, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 2;
    int result = sol.characterReplacement(s, k);
    cout << "The length of the longest substring after at most " << k 
    << " replacements is: " << result << endl;
    return 0;
}
