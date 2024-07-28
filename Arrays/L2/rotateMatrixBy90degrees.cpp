#include <bits/stdc++.h>

using namespace std;

/* brute force: time:O(n^2) space:O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,0));

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                ans[j][n-i-1]= matrix[i][j];
            }
        }
        // Assign the rotated matrix back to the original matrix
        matrix = ans;
    }
};
*/


// optimal: time:O(n^2)  space:O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        //first we take transpose of the matrix
        for(int i = 0; i <n-1; i++){
            // traverse only upper hal
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //then we take mirror image about the middle vertical line
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
int main(){
    vector<vector<int>>matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution sol;
    sol.rotate(matrix);
    // Print the rotated matrix
    cout<<"matrix after rotation is "<<endl;
    for(auto row : matrix){
        for(auto num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}