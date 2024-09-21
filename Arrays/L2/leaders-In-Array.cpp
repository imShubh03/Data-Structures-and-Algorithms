#include <bits/stdc++.h>
using namespace std;

/* brute: time:O(n^2) space:O(1) used space to return ans
class Solution{
public:
    vector<int> findLeaders(vector<int> &arr, int n){
        vector<int> ans;

        for (int i = 0; i < n; i++){
            bool leader = true;

            for (int j = i + 1; j < n; j++){
                if (arr[j] > arr[i]){
                    leader = false;
                    break;
                }
            }

            if (leader){
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};
*/

// optimal time:O(n) space:O(1) again, used to store the ans
class Solution{
public:
    vector<int> leaders(int n, int arr[]){
        vector<int> ans;
        int maxi = INT_MIN;

        for (int i = n - 1; i >= 0; i--){
            if (arr[i] >= maxi){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n = 6;
    int arr[] = {16, 17, 4, 3, 5, 2};

    Solution sol;
    vector<int> result = sol.leaders(n, arr);

    for (int leader : result)
    {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
