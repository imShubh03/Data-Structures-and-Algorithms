#include<bits/stdc++.h>
using namespace std;

/* time:O(n^2)  space:O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int largest = nums[i];
            int smallest = nums[i];

            for (int j = i + 1; j < n; j++) {
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);

                ans += (largest - smallest);
            }   
        }
        return ans;
    }
};
*/

// optimised : time:O(10n) space : O(10n)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

private:
    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Calculate how many subarrays nums[i] is the minimum
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += static_cast<long long>(nums[i]) * left[i] * right[i];
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Calculate how many subarrays nums[i] is the maximum
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += static_cast<long long>(nums[i]) * left[i] * right[i];
        }
        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    long long result = sol.subArrayRanges(nums);

    cout << "The sum of all subarray ranges is: " << result << endl;

    return 0;
}
