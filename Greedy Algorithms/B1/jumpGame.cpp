#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        for(int i = 0; i < n; i++) {
            if(i > maxInd) return false;
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 1, 1, 0, 2, 5};

    bool result = sol.canJump(nums);
    if (result) {
        cout << "You can reach the last index." << endl;
    } else {
        cout << "You cannot reach the last index." << endl;
    }

    return 0;
}
