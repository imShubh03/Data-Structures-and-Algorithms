#include<bits/stdc++.h>
using namespace std;

/*
void findPermutations(vector<int> &A, int l, int r, vector<vector<int>> &perms) {
    if(l == r) {
        perms.push_back(A);  
    } else {
        for(int i = l; i <= r; i++) {
            swap(A[l], A[i]);  // Swap to create new permutation
            findPermutations(A, l + 1, r, perms);  // Recurse
            swap(A[l], A[i]);  // Backtrack
        }
    }
}
vector<int> nextGreaterPermutation(vector<int> &A) {
    vector<vector<int>> perms;
    findPermutations(A, 0, A.size() - 1, perms);  
    sort(perms.begin(), perms.end());  
    for(int i = 0; i < perms.size(); i++) {
        if(perms[i] == A && i < perms.size() - 1) {
            return perms[i + 1];  
        }
    }
    // If no greater permutation, return the smallest one
    return perms[0];  
}
*/

// better inbuilt STL time:O(n) space:O(1)
vector<int> nextGreaterPermutation(vector<int> &A) {
    next_permutation(A.begin(), A.end());
    return A;
}

int main() {
    vector<int> A = {1, 2, 3};
    vector<int> result = nextGreaterPermutation(A);

    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
