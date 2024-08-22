#include <bits/stdc++.h> 
using namespace std;

/* brute time:O(n^2) space:O(1)
class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> knowMe(n, 0);
        vector<int> Iknow(n, 0);
        
        // Iterate over the matrix to populate knowMe and Iknow arrays
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        
        // Check for a celebrity
        for (int i = 0; i < n; i++) {
            if (knowMe[i] == n - 1 && Iknow[i] == 0) {
                return i;
            }
        }
        
        return -1; // No celebrity found
    }
};
*/

// time:O(2n) space:O(1)
class Solution {
public:
    
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, bottom = n - 1;

        // Narrow down the candidate
        while (top < bottom) {
            if (mat[top][bottom] == 1) {
                top++;
            } else {
                bottom--;
            }
        }

        // Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != top) { // Skip checking the diagonal
                if (mat[top][i] == 1 || mat[i][top] == 0) {
                    return -1;
                }
            }
        }

        return top; // The candidate is a celebrity
    }
};


int main() {
    Solution sol;
    
    // Example input matrix
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    
    int result = sol.celebrity(mat);
    
    if (result != -1) {
        cout << "Celebrity ID: " << result << endl;
    } else {
        cout << "No Celebrity Found" << endl;
    }
    
    return 0;
}
