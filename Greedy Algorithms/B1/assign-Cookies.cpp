#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();
        int l = 0, r = 0;

        // Use two pointers to assign cookies to children
        while (l < m && r < n) {
            if (g[r] <= s[l]) {
                // If the current cookie can satisfy the current child
                // Move to the next child
                r++; 
            }
            // Move to the next cookie
            l++; 
        }
        return r; 
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> g1 = {1, 2, 3}; // Greed factors
    vector<int> s1 = {1, 1};    // Cookie sizes
    cout << "Example 1: " << solution.findContentChildren(g1, s1) << endl; 

    return 0;
}
