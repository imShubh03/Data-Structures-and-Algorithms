#include <bits/stdc++.h>
using namespace std;


//tc:O(m*n) SC:O(m*n)
string printLCS(string &s, string &t){
    int m = s.length();
    int n = t.length();

    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    // fill dp table
    for(int i =1; i<=m; i++){
        for(int j =1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i = m, j=n;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    
    string s, t;
    cin>>s;
    cin>>t;

    string res = printLCS(s, t);
    cout<<res;

    return 0;
}
