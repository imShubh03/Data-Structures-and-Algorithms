#include <bits/stdc++.h>
using namespace std;

/* brute : time :O(n^2) space:O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) { 
                if (nums[j] == 0) {
                    zeros++;
                }
                if (zeros <= k) {
                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                } else {
                    break;
                }
            }
        }
        return maxlen;
    }
};
*/

// better time:O(2n) space:O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int maxlen = 0, zeros = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }

        return maxlen;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    int k = 2;

    int result = sol.longestOnes(nums, k);
    cout << "The longest subarray with at most " << k << " zeros is of length: " << result << endl;

    return 0;
}