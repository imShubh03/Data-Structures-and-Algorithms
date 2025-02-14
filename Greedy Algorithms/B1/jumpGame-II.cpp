#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int>& nums, int ind, int jumps) {
        int n = nums.size();
        if (ind >= n - 1) return jumps; // If we reach the last index, return jumps count
        
        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) { // Try all possible jumps
            minJumps = min(minJumps, solve(nums, ind + i, jumps + 1));
        }

        return minJumps;
    }

    int jump(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};

*/

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
