#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* time: O(n^2) space:O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + n - 1; j++) {
                int ind = j % n;
                if (nums[ind] > nums[i]) {
                    ans[i] = nums[ind];
                    break;
                }
            }
        }
        return ans;
    }
    */

    //optimised : time:O(4n) space :O(2n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i = 2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <=nums[i%n]){
                st.pop();
            }

            if(i<n){
                if(st.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }

};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1}; 
    vector<int> result = solution.nextGreaterElements(nums);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
