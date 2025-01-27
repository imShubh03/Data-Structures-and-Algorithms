#include <bits/stdc++.h>
using namespace std;

/* TC: O(n^2)  SC:O(1)
class Solution{
    public:
    int numberOfSubstrings(string &s){
        int n = s.size();
        int cnt = 0;
        for(int i =0; i<n; i++){
            vector<int>hash(3, 0);
            for(int j = i; j<n; j++){
                hash[s[j] - 'a']++;

                if(hash[0] > 0 && hash[1] > 0 && hash[2] > 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
*/

// TC:O(n) SC:O(1)
class Solution{
public:
    int numberOfSubstrings(string &s){
        int n = s.size();
        vector<int>lastSeen(3, -1);
        int cnt = 0;
        for(int i =0; i<n; i++){
            //last seen this elem at idx i
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt = cnt + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
            }
        }
    }
};

int main() {
    
    string s;
    cin >>s;

    Solution sol;
    int ans = sol.numberOfSubstrings(s);
    cout<< ans ;

    return 0;
}