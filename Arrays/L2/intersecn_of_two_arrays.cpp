#include <bits/stdc++.h>

using namespace std;

/*   time: O(n logn)+O(n logm)+ O(n)+O(m)   space:O(min(n,m))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                // Found intersection, to avoid duplications
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
*/

//optimised : using unordered_map   time:O(m+n)  space:O(min(m,n))
class Solution {
    public:
    vector<int>intersection(vector<int>&nums1,vector<int>&nums2){
        vector<int>ans;
        unordered_map<int,int>map;
        for(int num: nums1){
            map[num]++;
        }

        //check the elem of num2 agains the elem of map
        for(auto it: nums2){
            if(map[it]>0){
                ans.push_back(it);
                map[it]=0;
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
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
