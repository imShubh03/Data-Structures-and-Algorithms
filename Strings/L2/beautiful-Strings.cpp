#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string generate(int n, bool zero){
        string ans = "";
        if(n == 0) return 0;

        if(zero){
            ans += '0';
            n--;
        }
        else{
            ans += '1';
            n--;
        }
        while(n > 0){
            char temp = ans[ans.size() - 1];

            if(temp == '0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
            n--;
        }
        return ans;
    }
    int compare(string &s, string &gen1, int n){
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i] != gen1[i]){
                ans++;
            }
        }
        return ans;
    }
    int makeBeautiful(string &s){
        int n = s.length();

        string gen1 = generate(n, true);
        string gen2 = generate(n, false);

        int diff1 = compare(s, gen1, n);
        int diff2 = compare(s, gen2, n);

        return min(diff1, diff2);
    }
};

int main() {

    string s;
    cin >> s;

    Solution sol;
    int ans = sol.makeBeautiful(s);
    cout<< ans <<endl;

    return 0;
}