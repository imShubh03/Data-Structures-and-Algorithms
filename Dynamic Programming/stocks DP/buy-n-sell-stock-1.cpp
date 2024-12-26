#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProfit(vector<int> &nums, int n){
        int mini = nums[0];
        int maxprofit = 0;
        for(int i=1; i<n; i++){
            int cost = nums[i] - mini;
            maxprofit = max(maxprofit, cost);
            mini = min(mini, nums[i]);
        }
        return maxprofit;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int>prices(n);

    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    Solution sol;
    int ans = sol.maxProfit(prices, n);
    cout<<ans;

    return 0;
}