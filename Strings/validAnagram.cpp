#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    bool isAnagram(string s, string t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};
int main() {
    Solution sol;
    cout<<"enter the two stings"<<endl;
    string s;
    string t;
    cin>>s;
    cin>>t;

    bool ans= sol.isAnagram(s,t);
    cout<<ans;

    return 0;
}