#include <bits/stdc++.h>
using namespace std;

/*
void moveZeroes(int nums[], int n) {
    vector<int> nonZeros;
    // Collect all non-zero elements
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nonZeros.push_back(nums[i]);
        }
    }
    // Place non-zero elements back into the original array
    for(int i = 0; i < nonZeros.size(); i++) {
        nums[i] = nonZeros[i];
    }
    // Fill the rest of the array with zeros
    for(int i = nonZeros.size(); i < n; i++) {
        nums[i] = 0;
    }
}
*/

void moveZeroes(int nums[], int n) {
    int j = -1;

    // Find the first zero
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) {
            j = i;
            break;
        }
    }

    // If no zero is found, no need to do anything
    if (j == -1) {
        return;
    }

    // Traverse the rest of the array and swap non-zero elements with zero at index 'j'
    for(int i = j + 1; i < n; i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;  // Move 'j' to the next zero
        }
    }
}

int main() {
    int n;
    
    cin >> n;

    int nums[n];

    // Input the array elements
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Move all zeros to the end
    moveZeroes(nums, n);

    // Output the modified array
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
