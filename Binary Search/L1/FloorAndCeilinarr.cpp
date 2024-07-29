#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFloor(vector<int>& a, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] <= x) {
                ans = a[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findCeil(vector<int>& a, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] >= x) {
                ans = a[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(vector<int>& a, int n, int x) {
        int f = findFloor(a, n, x);
        int c = findCeil(a, n, x);
        return make_pair(f, c);
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 8, 15, 19, 29};
    int x = 10;
    Solution sol;
    pair<int, int> result = sol.getFloorAndCeil(arr, arr.size(), x);
    cout << "Floor of " << x << " is: " << result.first << endl;
    cout << "Ceil of " << x << " is: " << result.second << endl;

    return 0;
}
