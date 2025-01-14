#include <bits/stdc++.h>
using namespace std;

/*
void solve(vector<int> &A, vector<vector<int>> &ans, vector<int> &ds, vector<int> &vis){
    //base case
    if(ds.size() == A.size()){
        ans.push_back(ds);
        return;
    }

    //iterate over the arr

    for(int i =0; i<A.size(); i++){
        if(!vis[i]){
            ds.push_back(nums[i]);
            vis[i] = 1;
            solve(A, ans, ds, vis);
            //back track
            vis[i] = 0;
            ds.pop_back();
        }
    }
}
vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size();
    vector<vector<int>>ans;
    vector<int>ds;
    vector<int>vis(n, 0);
    solve(A, ans, ds, vis);
    sort(ans.begin(), ans.end());

    for(int i =0; i<ans.size(); i++){
        if(ans[i] == A && i< ans.size() - 1){
            return ans[i+1];
        }
    }
    return ans[0];
}
*/

/*
void findPermutations(vector<int> &A, int l, int r, vector<vector<int>> &perms) {
    if(l == r) {
        perms.push_back(A);
    } else {
        for(int i = l; i <= r; i++) {
            swap(A[l], A[i]);  // Swap to create new permutation
            findPermutations(A, l + 1, r, perms);  // Recurse
            swap(A[l], A[i]);  // Backtrack
        }
    }
}
vector<int> nextGreaterPermutation(vector<int> &A) {
    vector<vector<int>> perms;
    findPermutations(A, 0, A.size() - 1, perms);
    sort(perms.begin(), perms.end());
    for(int i = 0; i < perms.size(); i++) {
        if(perms[i] == A && i < perms.size() - 1) {
            return perms[i + 1];
        }
    }
    // If no greater permutation, return the smallest one
    return perms[0];
}
*/

// better inbuilt STL time:O(n) space:O(1)
vector<int> nextGreaterPermutation(vector<int> &A)
{
    next_permutation(A.begin(), A.end());
    return A;
}

/*  OPTIMAL
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first index (from the end) where nums[i] < nums[i+1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no such index is found, reverse the entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest number greater than nums[idx] to the right of idx
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 4: Reverse the part of the array to the right of idx
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

*/

int main()
{
    vector<int> A = {1, 2, 3};
    vector<int> result = nextGreaterPermutation(A);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
