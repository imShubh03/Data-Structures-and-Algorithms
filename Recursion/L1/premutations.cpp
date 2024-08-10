#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPerm(vector<int>& nums, vector<int>& ds, vector<int>& freq, vector<vector<int>>& ans) {
        // Base case: if the current permutation is of the same size as nums
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not yet included in the current permutation
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1; // Mark as used
                findPerm(nums, ds, freq, ans);
                freq[i] = 0; // Backtrack: unmark the current element
                ds.pop_back(); // Remove the last element to try another permutation
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0); // Initialize freq as a vector

        findPerm(nums, ds, freq, ans);
        return ans; // Return the result
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = sol.permute(nums);

    // Print the result
    cout << "All permutations are:\n";
    for ( auto permutation : result) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
