#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier){
        int n = nums.size();
        
        while(k--){
            auto indx = min_element(nums.begin(), nums.end());

            (*indx) = (*indx) * multiplier;
        }

        return nums;
    }
};
*/


class Solution {
public:
    typedef pair<int, int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>>pq;

        for(int i =0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            int minval = pq.top().first;
            int indx = pq.top().second;

            pq.pop();

            nums[indx] = minval * multiplier;

            pq.push({nums[indx], indx});
        }

        return nums;
    }
};

int main() {
    
    int n, k, multiplier;
    cin>>n;

    vector<int>nums(n);

    for(int i =0; i<n; i++){
        cin>>nums[i];
    }

    Solution sol;

    vector<int>ans = sol.getFinalState(nums, k, multiplier);

    for(int i =0; i<ans.size(); i++){
        cout<< ans[i] <<endl;
    }


    return 0;
}