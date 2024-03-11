/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int left = nums1.size();
        int right = nums2.size();
        int i = 0;
        int j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < left && j < right) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                // Found intersection
                // to avoid duplications
                // if last added elem in ans is not equalto nums[i] ele
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums1, nums2;

    // Input for nums1
    int n;
    cout << "Enter the size of nums1: ";
    cin >> n;
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums1.push_back(num);
    }

    // Input for nums2
    cout << "Enter the size of nums2: ";
    cin >> n;
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums2.push_back(num);
    }

    // Find intersection
    vector<int> result = solution.intersection(nums1, nums2);
    // Output intersection
    cout << "Intersection: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
