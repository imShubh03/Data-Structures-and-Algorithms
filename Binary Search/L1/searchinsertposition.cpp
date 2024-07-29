#include <iostream>
#include <vector>

using namespace std;
//similar to lower bound


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 7};
    int target = 5;
    // Call searchInsert to find the insertion index for target
    int insertIndex = sol.searchInsert(nums, target);
    // Output the result
    cout << "Target " << target << " should be inserted at index: " << insertIndex << endl;
    return 0;
}
