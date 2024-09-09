#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Handle edge case where no jumps are needed
        
        int l = 0, r = 0; // Initial range
        int ans = 0; // Number of jumps
        
        while (r < n - 1) { // Continue until we reach or exceed the last element
            int farthest = r; // Find the farthest we can reach from the current range
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1; // Move to the next range
            r = farthest; // Update the end of the range
            ans++; // Increment the jump count
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input array

    int result = sol.jump(nums);
    cout << "Minimum number of jumps to reach the last index: " << result << endl;

    return 0;
}
