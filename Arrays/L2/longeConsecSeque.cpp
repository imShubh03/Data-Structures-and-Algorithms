#include<bits/stdc++.h>

using namespace std;

/*  time:O(n^2) space:O(1)
class Solution {
public:
    bool lineSearch(vector<int>& nums, int num) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == num) {
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 1;

            while (lineSearch(nums, x + 1) == true) {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
*/


/*  better:  time: O(nlogn)+O(n) space:O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int lastSmall =INT_MIN;
        int cnt =0;
        int longest = 1;

        for(int i =0;i<n;i++){
            if(nums[i]-1 == lastSmall){
                cnt++;
                lastSmall= nums[i];
            }
            else if(nums[i]!=lastSmall){
                cnt=1;
                lastSmall =nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) { // if ur prev ele is not there  u will be part of the long seque
                int cnt = 1;
                int x = it; // so x will be first ele
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

int main(){
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive elements: " << s.longestConsecutive(nums) << endl;
    return 0;
}