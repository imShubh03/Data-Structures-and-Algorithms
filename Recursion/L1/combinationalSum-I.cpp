#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void findCombi(vector<int>&nums, int target, int index, vector<vector<int>>&ans, vector<int>&ds){
        int n = nums.size();
        // base case
        if(index==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick elem
        if(nums[index]<=target){
            ds.push_back(nums[index]);
            findCombi(nums,target-nums[index],index,ans,ds);
            ds.pop_back();
        }

        //not pick
        findCombi(nums,target,index+1,ans,ds);

    }
    public:
    vector<vector<int>>combinationSum(vector<int>&candidates, int target){
        vector<vector<int>>ans;
        vector<int>ds;

        findCombi(candidates, target, 0, ans, ds);

        return ans;
    }
};

int main() {

    vector<int>candidates={2,3,6,7};
    int target = 7;
    Solution sol;

    vector<vector<int>>res = sol.combinationSum(candidates,target);


    cout<<"printing the results"<<endl;

    for(auto it : res){
        cout<<"[";
        for(size_t i =0; i<it.size();i++){
            cout<<" "<<it[i]<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}