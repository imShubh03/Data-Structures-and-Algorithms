#include <bits/stdc++.h>
using namespace std;

/* TC:O(n)  SC:O(n/2)
class Solution{
public:
    int maxDepth(string &s){
        stack<char>st;
        int res = 0;
        for(char &ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else{
                st.pop();
            }

            res = max(res, (int)st.size());
        }
        return res;
    }
};
*/

// TC:O(n)  SC:O(1)
class Solution{
public:
    int maxDepth(string &s){
        int n = s.size();
        int openBrackets = 0;
        int res = 0;
        for(int i =0; i<n; i++){
            if(s[i] == '('){
                openBrackets++;
            }
            else if(s[i] == ')'){
                openBrackets--;
            }
            res = max(res, openBrackets);
        }
        return res;
    }
};


int main() {
    string s;
    cin>>s;

    Solution sol;
    int ans = sol.maxDepth(s);
    cout<<ans<<endl;

    return 0;
}