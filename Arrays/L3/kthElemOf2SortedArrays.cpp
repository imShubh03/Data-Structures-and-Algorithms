#include <iostream>
#include <vector>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k) {
    int total = n + m;
    vector<int> newArr(total);
    
    int left = 0;
    int right = 0;
    int i = 0;
    
    // Merge the two arrays into newArr
    while (left < n && right < m) {
        if (arr1[left] < arr2[right]) {
            newArr[i] = arr1[left];
            left++;
        } else {
            newArr[i] = arr2[right];
            right++;
        }
        i++;
    }
    
    // Copy the remaining elements of arr1, if any
    while (left < n) {
        newArr[i] = arr1[left];
        left++;
        i++;
    }
    
    // Copy the remaining elements of arr2, if any
    while (right < m) {
        newArr[i] = arr2[right];
        right++;
        i++;
    }
    
    // Return the k-th element (1-based index)
    if (k > 0 && k <= total) {
        return newArr[k - 1];
    }
    
    return -1;  // Return -1 if k is out of bounds
}

int main() {
    // Example arrays
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int n = arr1.size();
    int m = arr2.size();
    int k = 5;  // Find the 5th element in the merged array

    int result = kthElement(arr1, arr2, n, m, k);

    cout << "The " << k << "-th element in the merged array is: " << result << endl;

    return 0;
}