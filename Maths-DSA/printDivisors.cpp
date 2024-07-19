#include <bits/stdc++.h>

using namespace std;

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

int main() {
    int n;
    cin>>n;
    Solution sol;
    
    sol.printAllDivisors(n);

    return 0;
}