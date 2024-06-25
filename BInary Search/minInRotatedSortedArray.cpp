#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minElem(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[low] <= arr[mid]) {
                ans = min(arr[low], ans);
                low = mid + 1;
            } else {
                ans = min(arr[mid], ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements in array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int min = sol.minElem(arr);

    cout << "Minimum element: " << min << endl;

    return 0;
}
