#include <bits/stdc++.h>

using namespace std;

/*  brute time O(n)  space O(1)
class Solution{
    public:
    void printAllDivisors(int n){
        for(int i=1;i<=n;i++){
            if(n%i == 0){
                cout<< i<<" ";
            }
        }
    }
};
*/

//optimal
class Solution{
    public:
    void printAllDivisors(int n){
        vector<int>ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i == 0){
                ans.push_back(i);

                if((n/i) != i){
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(),ans.end());

        for(auto it : ans)  cout<<it <<" ";
    }
};


int main() {
    int n;
    cin>>n;
    Solution sol;
    
    sol.printAllDivisors(n);

    return 0;
}