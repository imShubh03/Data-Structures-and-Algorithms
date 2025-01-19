#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxCount(vector<int> &freq) {
        int maxCnt = 0;
        for (int i = 0; i < 26; i++) {
            maxCnt = max(maxCnt, freq[i]);
        }
        return maxCnt;
    }

    int getMinCount(vector<int> &freq) {
        int minCnt = INT_MAX;
        for (int i = 0; i < 26; i++) {
            // Only consider characters that appear in the substring
            //eg for 'a' max is 1 and min is 1
            if (freq[i] != 0) { 
                minCnt = min(minCnt, freq[i]);
            }
        }
        return minCnt;
    }

    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int beauty = getMaxCount(freq) - getMinCount(freq);
                sum += beauty;
            }
        }

        return sum;
    }
};


int main() {
    
    string s;
    cin>> s;

    Solution sol;
    int ans = sol.beautySum(s);
    cout<<ans;

    return 0;
}