#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st;
        
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    for(int l = k+1; l<n; l++){
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];

                        if(sum == target){
                            vector<int>temp = { nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset;
                for (int k = j + 1; k < n; k++) {
                    long long sum = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                    if (hashset.count(sum)) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)sum};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
*/

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    } else if (sum > target) {
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    int n, target;
    cin>>n >> target;

    vector<int>arr(n);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;

    vector<vector<int>>res = sol.fourSum(arr, target);


    for(auto it : res){
        cout<<"[";
        for(auto j : it){
            cout<< j << " ";
        }
        cout<<"]";
        cout<< endl;
    }

    

    return 0;
}