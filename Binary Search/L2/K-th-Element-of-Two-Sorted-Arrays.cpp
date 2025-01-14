#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int kthElement(vector<int> &nums1, vector<int>& nums2, int m, int n, int k) {
        if (m > n) return kthElement(nums2, nums1, n, m, k);

        int low = max(0, k - n), high = min(k, m);
        int left = k;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            if (mid1 > 0) l1 = nums1[mid1 - 1];

            int l2 = INT_MIN;
            if (mid2 > 0) l2 = nums2[mid2 - 1];

            int r1 = INT_MAX;
            if (mid1 < m) r1 = nums1[mid1];

            int r2 = INT_MAX;
            if (mid2 < n) r2 = nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1; // In case no valid k-th element is found
    }
};

int main() {

    int m, n, k;
    cin>>m>>n;
    cin>>k;

    vector<int>arr1, arr2;

    for(int i =0; i<m; i++){
        cin>>arr1[i];
    }

    for(int i =0; i<n; i++){
        cin>>arr2[i];
    }

    Solution sol;
    int ans = sol.kthElement(arr1, m, arr2, n, k);
    cout<<ans<<endl;

    return 0;
}