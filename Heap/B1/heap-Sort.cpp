#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr, int n) {
        int size = n; // Start with the full size of the heap
        while (size > 1) {
            swap(arr[0], arr[size - 1]); // Move current root to the end
            size--;                      // Reduce heap size
            heapify(arr, size, 0);       // Heapify the reduced heap
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;

    // Build max heap in main
    for (int i = n / 2 - 1; i >= 0; i--) {
        sol.heapify(arr, n, i);
    }

    // Sort the heap
    sol.heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
