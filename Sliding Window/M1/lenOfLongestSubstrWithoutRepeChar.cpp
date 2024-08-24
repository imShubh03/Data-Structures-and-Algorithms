#include <bits/stdc++.h>
using namespace std;

/* brute : time:O(n^2) space:O(1)
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        int n = s.length();
        int maxlen =0;
        for(int i =0; i<n; i++){
            int hash[256]={0};
            for(int j =i; j<n; j++){
                if(hash[s[j]]==1) break;

                int len = j - i + 1;
                maxlen = max(maxlen, len);
                hash[s[j]]=1;
            }
        }
        return maxlen;
    }
};
*/


// optimised : time:O(n) , space:O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int maxlen = 0;
        int hash[256]; 
        fill(hash, hash + 256, -1); // Properly initialize all elements to -1

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1; // Move the left pointer
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);
            hash[s[r]] = r; // Update the hash with the latest index of the character

            r++;
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;
    cin>>s;
    int ans = sol.lengthOfLongestSubstring(s);
    cout<<"max len is "<<ans<<endl;

    return 0;
}