#include <bits/stdc++.h>
using namespace std;

/*
not the same as prev one as prev cant work with duplica arr
arr = [3 1 2 3 3 3 3]  here arr[mid] == arr[low] == arr[high] so we handle this case
*/

class Solution{
public:
    bool searchInArray(vector<int> &arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (arr[mid] == target){
                return true;
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


int main(){
    int n;
    cout << "enter total elements" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "enter  elements in the array" << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cout << "enter the target ?" << endl;
    cin >> target;

    Solution sol;
    bool result = sol.searchInArray(arr, target);
    cout << "index will be " << result;
    return 0;
}