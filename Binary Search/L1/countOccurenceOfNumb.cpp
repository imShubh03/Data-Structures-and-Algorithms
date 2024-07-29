#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOccurrences(vector<int>& arr, int x) {
        int cnt = 0;
        for (int num : arr) {
            // counting the occurrences:
            if (num == x) cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int x = 8;
    int ans = solution.countOccurrences(arr, x);
    cout << "The number of occurrences of " << x << " is: " << ans << "\n";
    return 0;
}
