#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int index = -1;
        int maxCnt = 0;

        for (int i = 0; i < n; i++) {
            int cntRows = 0;

            for (int j = 0; j < m; j++) {
                cntRows += matrix[i][j];
            }

            if (cntRows > maxCnt) {
                maxCnt = cntRows;
                index = i;
            }
        }
        return index;
    }
};
*/


class Solution{
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            // Use lower_bound to find the first occurrence of '1'
            int pos = lower_bound(matrix[i].begin(), matrix[i].end(), 1) - matrix[i].begin();
            int cnt_ones = m - pos; // Count of 1's in the row

            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>>matrix;

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>> matrix[i][j];
        }
    }

    Solution sol;
    int ans = sol.rowWithMax1s(matrix, n, m);
    cout<<ans;

    return 0;
}