#include <bits/stdc++.h>

using namespace std;

/* time: (NlogN) space:O(1)
class Solution{
    public:
    bool isAnagram(string s, string t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};
*/

/* time: O(n) , space:O(n)
class Solution{
    public:
    bool isAnagram(string s, string t){

        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char,int>map;

        for(auto it : s){
            map[it]++;
        }

        for(auto it : t){
            map[it]--;
        }

        for(auto pair:map){
            if(pair.second != 0){
                return false;
            }
        }

        return true;
    }
};
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<int>freq(26);

        for(char &ch : s){
            freq[ch - 'a']++;
        }

        for(char &ch : t){
            freq[ch - 'a']--;
        }

        for(int it : freq){
            if(it != 0){
                return false;
            }
        }

        return true;
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