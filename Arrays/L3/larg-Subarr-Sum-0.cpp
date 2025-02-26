#include <bits/stdc++.h>
using namespace std;

/* TC: O(n^3)  SC:O(1)
class Solution {
    public:
    int maxLen(vector<int>& arr) {
        // code here
        int maxlen = 0;
        int n = arr.size();
    
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k<=j; k++){
                    sum += arr[k];
                }
                if(sum == 0){
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};
*/

/* TC:O(n^2)  SC:O(1)
class Solution{
public:
    int maxLen(vector<int> &arr){
        
        int maxlen = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i; j < n; j++){
                sum += arr[j];

                if (sum == 0){
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};
*/

// TC O(n) SC:O(1)
class Solution {
    public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int maxlen = 0;
        int sum =0;
        
        unordered_map<int, int>mp;
        
        for(int i =0; i<n; i++){
            sum += arr[i];
            
            if(sum == 0){
                maxlen = i + 1;   
            }
            else{
                if(mp.count(sum) == 1){
                    maxlen = max(maxlen, i - mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        return maxlen;
    }
};

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution sol;
    int ans = sol.maxLen(arr);

    return 0;
}