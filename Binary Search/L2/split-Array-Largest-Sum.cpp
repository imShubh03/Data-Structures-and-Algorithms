//same as agress cows and painters partition

#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int count = 1;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];
            } else {
                count++;
                currentSum = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        for (int i = low; i <= high; i++) {
            int requiredParts = countSubarrays(nums, i);
            if (requiredParts == k) {
                return i;
            }
        }
        return -1;
    }
};
*/


class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int count = 1;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];
            } else {
                count++;
                currentSum = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int answer = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int requiredParts = countSubarrays(nums, mid);

            if (requiredParts > k) {
                low = mid + 1;
            } else {
                answer = mid;
                high = mid - 1;
            }
        }
        return answer;
    }
};


int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    Solution sol;
    int result = sol.splitArray(nums, k);
    cout << result << endl;

    return 0;
}
