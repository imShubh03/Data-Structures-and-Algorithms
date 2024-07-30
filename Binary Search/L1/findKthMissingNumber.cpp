#include <iostream>
#include <vector>
using namespace std;

/*  brute: time:O(n)  space:O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};
*/

//optimal :time:O(logn) space:O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low =0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid]-(mid+1);

            if(missing < k){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return k+high+1;
    }
};

int main() {
    Solution solution;

    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    int ans = solution.findKthPositive(arr1, k1) ;
    cout << "The " << k1 << "-th missing positive integer is: " << ans<< endl;

    return 0;
}
