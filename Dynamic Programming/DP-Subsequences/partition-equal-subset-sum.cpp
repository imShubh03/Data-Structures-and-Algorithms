#include <bits/stdc++.h>
using namespace std;

//TC:O(n * target) SC:O(totalsum)
class Solution {
public:
    // Function to check if a subset with sum equal to target exists
    bool subsetsumK(vector<int>& nums, int n, int target) {
        vector<bool> prev(target + 1, false); // Previous row for DP
        vector<bool> curr(target + 1, false); // Current row for DP
        
        prev[0] = curr[0] = true; // Base case: sum 0 is always achievable
        
        if (nums[0] <= target) {
            prev[nums[0]] = true; // If the first element is within target, set it
        }
        
        for (int i = 1; i < n; i++) { // Loop over each number
            for (int j = 1; j <= target; j++) { // Loop over each possible sum
                bool nottake = prev[j]; // Not taking the current element
                bool take = false;
                if (j >= nums[i]) {
                    take = prev[j - nums[i]]; // Taking the current element
                }
                curr[j] = take || nottake; // Update DP value
            }
            prev = curr; // Move to the next row
        }
        
        return prev[target]; // Return if target sum is achievable
    }

    // Function to check if array can be partitioned into two equal subsets
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0); // Total sum of array
        
        if (totalsum % 2 == 1) return false; // If odd, cannot split equally
        
        int target = totalsum / 2; // Target subset sum
        return subsetsumK(nums, n, target); // Check if subset sum exists
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (solution.canPartition(nums)) {
        cout << "Yes, the array can be partitioned into two equal subsets." << endl;
    } else {
        cout << "No, the array cannot be partitioned into two equal subsets." << endl;
    }

    return 0;
}
