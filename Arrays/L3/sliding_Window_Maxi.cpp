#include<bits/stdc++.h>
using namespace std;

/* brute force :time: O(n-k * k) space:O(n-k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i <= n - k; i++) {
            int maxi = nums[i];
            for(int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi); 
        }
        
        return ans;
    }
};
*/

// optimised: time:O(2n) space:O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check if the front of the deque is out of the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain the deque such that elements are in decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current element index at the back of the deque
            dq.push_back(i);

            // Once we have processed at least k elements, start adding results
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = solution.maxSlidingWindow(nums, k);
    
    cout << "Max elements in sliding window: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
