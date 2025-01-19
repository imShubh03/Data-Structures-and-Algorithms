#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countSubstr(string& s, int k){
        int n = s.length();
        int cnt =0;
        for(int i =0; i<n; i++){
            unordered_set<char>st;
            for(int j =i; j<n; j++){
                st.insert(s[j]);

                if(st.size() == k){
                    cnt++;
                }
                else if(st.size() > k){
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    int k;
    string s;
    cin>>s;
    cin>>k;

    Solution sol;
    int ans = sol.countSubstr(s, k);
    cout<<ans;

    return 0;
}