#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            } else {
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                }
                // If both are the same size, they both explode
                if (!ans.empty() && ans.back() == abs(asteroids[i])) {
                    ans.pop_back();   
                } else {
                    if (ans.empty() || ans.back() < 0) {
                        ans.push_back(asteroids[i]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> asteroids = {4,7,1,1,2,-3,-7,17,15,-16};
    
    // Calling the asteroidCollision method
    vector<int> result = solution.asteroidCollision(asteroids);
    
    // Output the result
    cout << "Resulting asteroids: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}
