#include <bits/stdc++.h>
using namespace std;


/*brute : time:O(n^2) space:O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false; // Check if the matrix is empty
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
*/

/* better: tine:O(n)*logm  space:O(1)
class Solution {
public:
    bool bs(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2; // avoid overflow
            if (arr[m] == target) return true;
            else if (arr[m] > target) h = m - 1;
            else l = m + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;  // check if matrix is empty
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            // if target can possibly be in the current row, do binary search
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                if (bs(matrix[i], target)) return true;
            }
        }
        return false;
    }
};
*/



int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 5;

    bool result = sol.searchMatrix(matrix, target);
    if (result) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
