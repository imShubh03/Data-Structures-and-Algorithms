#include <bits/stdc++.h>
using namespace std;

/*  brute force,  time:O(n) space:O(1)
class Solution{
    public:
    int searchInArray(vector<int> &arr, int target){
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(arr[i] == target)
                return i;
        }
        return -1;
    }
};
*/

//optimised : time:O(logn)  space:O(1)
class Solution{
public:
    int searchInArray(vector<int> &arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (arr[mid] == target){
                return mid;
            }
            if (arr[low] <= arr[mid]){
                if (arr[low] <= target && target <= arr[mid]){
                    high = low - 1;
                }
                else{
                    low = high + 1;
                }
            }
            else{
                if (arr[mid] <= target && target <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main()
{
    int n;
    cout << "enter total elements" << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "enter  elements in the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "enter the target ?" << endl;

    cin >> target;

    Solution sol;
    int result = sol.searchInArray(arr, target);

    cout << "index will be " << result;

    return 0;
}