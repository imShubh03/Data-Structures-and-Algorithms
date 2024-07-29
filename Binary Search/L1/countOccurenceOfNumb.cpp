#include <bits/stdc++.h>
using namespace std;

/*brute force time: O(n)  space:O(1)
class Solution {
public:
    int countOccurrences(vector<int>& arr, int x) {
        int cnt = 0;
        for (int num : arr) {
            // counting the occurrences:
            if (num == x) cnt++;
        }
        return cnt;
    }
};
*/

// optimized time: O(log n)  space:O(1)
// total occurenc = last occ - first occ + 1
class Solution{
    public:
    int firstOcc(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size()-1;
        int first =-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                first = mid;
                high = mid-1;
            }
            else if(arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return first;
    }
    int lastOcc(vector<int>&arr,int x){
        int low = 0;
        int high = arr.size()-1;
        int last =-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                last = mid;
                low = mid+1;
            }
            else if(arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return last;
    }
    pair<int,int>firstandlast(vector<int>&arr, int x){
        int first = firstOcc(arr,x);
        if(first == -1) return {-1,-1};
        int last = lastOcc(arr, x);
        return {first, last};
    }
    int countOccurrences(vector<int>& arr, int x) {
        pair<int,int>ans = firstandlast(arr,x);
        if(ans.first == -1) return 0;
        return (ans.second - ans.first + 1);
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int x = 8;
    int ans = solution.countOccurrences(arr, x);
    cout << "The number of occurrences of " << x << " is: " << ans << "\n";
    return 0;
}
