#include <bits/stdc++.h>
using namespace std;

/* brute : time:O(n * m) space:O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}
*/

/*better time:O(m) + O(logm)  space:O(1)
bool bs(vector<int>& arr, int target) {
        int len = arr.size();
        int l = 0;
        int h = len - 1;

        while (l <= h) {
            int m = (l + h) / 2;

            if (arr[m] == target) return true;
            else if (arr[m] > target) h = m - 1;
            else l = m + 1;
        }
        return false;
    }
bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        if (m == 0) return false; 
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            if (mat[i][0] <= target && target <= mat[i][n - 1]) {
                return bs(mat[i], target);
            }
        }
        return false;
}
*/

// optimised time:O(log(m*n)) space:O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m= mat.size();
    int n = mat[0].size();
    int len = m*n;

    int low =0;
    int high = len -1;

    while(low <= high){
        int mid = (low + high)/2;

        int row = mid/n;
        int col = mid%n;

        if(mat[row][col] == target){
            return true;
        }
        else if(mat[row][col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}




int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int target = 5;

    bool result = searchMatrix(mat, target);
    if(result){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    return 0;
}
