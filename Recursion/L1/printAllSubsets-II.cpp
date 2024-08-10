#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector< vector< int>> &ans) {
            
            ans.push_back(ds);
            for(int i = ind; i < nums.size(); i++){
                // Skip duplicates
                if(i != ind && nums[i] == nums[i-1]) continue;

                ds.push_back(nums[i]);
                findSubsets(i + 1, nums, ds, ans);
                ds.pop_back();
            }

        }

    public:
        vector<vector<int>> subsetsWithDup(vector<int> &nums)
        {
            vector<vector<int>> ans;
            vector<int> ds;
            sort(nums.begin(), nums.end());
            findSubsets(0, nums, ds, ans);
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 2, 3, 3};
    
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    // Print the result
    cout << "Unique subsets are:\n";
    for(const auto &subset : result) {
        cout << "[ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
