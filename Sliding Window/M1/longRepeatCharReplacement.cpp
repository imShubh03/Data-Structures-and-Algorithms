#include<bits/stdc++.h>
using namespace std;

/* brute: time:O(N^2)  space:O(26)
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
*/

/*
// optimised : time:O(2n) * 26 ,space:O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0, r=0;
        int maxlen=0, maxfreq=0;
        int hash[26] ={0};
        while(r < n){
            hash[s[r] - 'A']++;
            maxfreq= max(maxfreq, hash[s[r]- 'A']);
            // check if valid 
            // if not then trim down
            while((r-l+1)- (maxfreq) > k){ //not valid
                hash[s[l]- 'A']--;
                maxfreq=0;
                for(int i =0; i<26; i++){
                    maxfreq = max(maxfreq, hash[i]);
                }
                l++;
            }
            if((r - l + 1) - (maxfreq) <= k){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};
*/

// most optimised time:O(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0, r=0;
        int maxlen=0, maxfreq=0;
        int hash[26] ={0};
        while(r < n){
            hash[s[r] - 'A']++;
            maxfreq= max(maxfreq, hash[s[r]- 'A']);
            // check if valid 
            // if not then trim down
            if((r-l+1)- (maxfreq) > k){ //not valid
                hash[s[l]- 'A']--;
                l++;
            }
            if((r - l + 1) - (maxfreq) <= k){
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
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
