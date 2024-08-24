#include <bits/stdc++.h>
using namespace std;

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

int main() {
    Solution sol;
    string s;
    cin>>s;
    int ans = sol.lengthOfLongestSubstring(s);
    cout<<"max len is "<<ans<<endl;

    return 0;
}