#include <bits/stdc++.h>
using namespace std;

/* TC:O(m+n)  SC:O(m+n)
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        int len = ans.size();

        if (len % 2 == 1) {
            return ans[len / 2];
        }

        return (double)(ans[len / 2] + ans[len / 2 - 1]) / 2.0;
    }
};
*/

/*TC:O(m+n)  SC:O(1)
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        int len = ans.size();

        if (len % 2 == 1) {
            return ans[len / 2];
        }

        return (double)(ans[len / 2] + ans[len / 2 - 1]) / 2.0;
    }
};
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // make sure that first arr is smallest
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = m;
        int left = (m + n + 1) / 2;
        int len = (m + n);

        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < m) r1 = nums1[mid1];

            if (mid2 < n) r2 = nums2[mid2];

            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];

            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (len % 2 == 1) return max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};

int main() {

    int m, n;
    cin>> m >> n;

    vector<int>nums1(m);
    vector<int>nums2(n);

    for(int i = 0; i<m; i++) {
        cin>>nums1[i];
    }

    for(int i = 0; i<n; i++) {
        cin>>nums2[i];
    }

    Solution sol;

    double ans = sol.findMedianSortedArrays(nums1, nums2);
    cout<< ans <<endl;

    return 0;
}