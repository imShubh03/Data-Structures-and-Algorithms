#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    string longestCommonPrefix( vector<string>&strs){
        if(strs.empty()){
            return "";
        }
        int preLen=0;
        int minLen=1000;
        string minStr;

        //find the shortest string
        for(int i =0;i<strs.size();i++){
            int len = strs[i].size();

            if(len < minLen){
                minLen = len;
                minStr= strs[i];
            }
        }

        for(int i =0;i<minStr.size();i++){
            for(int j =0;j<strs.size();j++){
                if(strs[j][i] != minStr[i]){
                    return minStr.substr(0,preLen);
                }
            }
            preLen++;
        }
        return minStr.substr(0,preLen);
    }
};

int main() {
    
    Solution sol;

    vector<string>strs={"flower","flow","flight"};

    string ans = sol.longestCommonPrefix(strs);

    cout<<"the answer is : "<<ans<<endl;

    return 0;
}