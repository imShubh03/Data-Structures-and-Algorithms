#include <bits/stdc++.h>
using namespace std;

// TC : O(n 2^n) (loop*no of recurcall)  SC:O(n)

class Solution{
    public:
    void printSubStr(int index, string &str, string &ans, int n){
        //base case
        if(index==n){
            for(auto it:ans){
                cout<<it<<" ";
            }
            if(ans.empty()){
                cout<<"{}";
            }
            cout<<endl;
            return;
        }

        //pick the index
        ans.push_back(str[index]);
        printSubStr(index+1,str, ans, n);
        ans.pop_back();

        //donot pick the index
        printSubStr(index+1,str,ans,n);

    }

};

int main() {
    string str = "abdv";

    int index =0;
    string ans="";
    int n =4;

    Solution sol;
    sol.printSubStr(index,str,ans,n);

    return 0;
}