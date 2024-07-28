#include <bits/stdc++.h>
using namespace std;

/* brute force : time:O ((m*n)*(m+n)) space:O(1)
class Solution {
public:
    void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
        // set all non-zero elements as -1 in the row i:
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
        // set all non-zero elements as -1 in the col j:
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
        // Set -1 for rows and cols
        // that contains 0. Don't mark any 0 as -1:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, n, m, i);
                    markCol(matrix, n, m, j);
                }
            }
        }

        // Finally, mark all -1 as 0:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
        return matrix;
    }
};
*/



int main() {
    
    vector<vector<int>>matrix ={{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    int m = matrix.size();
    int n = matrix[0].size();
    Solution sol;
    vector<vector<int>> ans = sol.zeroMatrix(matrix,n,m);

    cout<<"the final ans "<<endl;
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
