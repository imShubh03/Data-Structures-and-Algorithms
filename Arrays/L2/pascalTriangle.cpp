#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    // Function to calculate nCr
    int nCr(int N, int R) {
        if (R > N) return 0; // If R > N, nCr is not defined
        long long res = 1;
        for (int i = 0; i < R; i++) {
            res = res * (N - i);
            res = res / (i + 1);
        }
        return res;
    }

    // Function to return the element at the specified nCr
    int findElementAtnCr(int N, int R) {
        return nCr(N, R);
    }

    /*
    vector<int> printNthrow(int N) {
        vector<int> ans;
        for (int col = 0; col < N; col++) { // Fix loop bounds (0-based indexing)
            ans.push_back(nCr(N - 1, col)); // Compute nCr for each column
        }
        return ans;
    }


    // Function to print the Nth row of Pascal's Triangle using an optimized approach
    vector<int> printNthrow(int N) {
        vector<int> res;
        res.push_back(1); // First element of the row is always 1
        long long ans = 1;
        for (int i = 1; i < N; i++) {
            ans = ans * (N - i);
            ans = ans / i;
            res.push_back(ans); // Append the current element of the row
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    int nCr(int n, int r){
        if( r == 0 || r == n){
            return 1;
        }
        long long res = 1;
        for(int i = 0; i < r; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int r = 0; r < numRows; r++){
            vector<int> temp;
            for(int c = 0; c <= r; c++){
                temp.push_back(nCr(r, c));
            }
            res.push_back(temp);
        }

        return res;
    }
};
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;  // 2D vector to store the triangle

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Create a row with `i+1` elements, all initialized to 1

            // Calculate the values in the middle of the row (excluding the first and last elements)
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);  // Add the row to the triangle
        }

        return triangle;
    }
};


int main() {
    Solution sol;

    /*
    int N, R;
    cin >> N >> R;
    int ans = sol.findElementAtnCr(N, R);
    */

    /*
    int N;
    cin >> N;
    vector<int> res = sol.printNthrow(N);
    for (int val : res) {
        cout << val << " "; // Print the row
    }
    */

    int n;
    cin>>n;
    vector<vector<int>> res = sol.generate(n);
    for (const auto& row : res) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }


    return 0;
}
