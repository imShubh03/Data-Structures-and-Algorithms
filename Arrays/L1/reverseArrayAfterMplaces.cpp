#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse

using namespace std;

void reverseAfterPosition(vector<int>& arr, int M) {
    // Check if M is within the valid range
    if (M < 0 || M >= arr.size()) {
        cout << "Invalid position M" << endl;
        return;
    }

    // Reverse the subarray from M+1 to the end
    reverse(arr.begin() + M + 1, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int M = 3;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    reverseAfterPosition(arr, M);

    cout << "Array after reversing from position " << M + 1 << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
