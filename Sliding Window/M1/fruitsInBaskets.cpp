#include <bits/stdc++.h>
using namespace std;

/* optimised : time:O(n^2) space: O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(fruits[j]);

                if (st.size() <= 2) {
                    maxlen = max(maxlen, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return maxlen;
    }
};
*/

/* better : time:O(2n) space:O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxlen = 0;
        map<int, int> mpp;

        while (r < n) {
            mpp[fruits[r]]++;  

            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]); 
                
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
*/


//optimised time:O(n) space:O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxlen = 0;
        map<int, int> mpp;

        while (r < n) {
            mpp[fruits[r]]++;  

            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]); 
                
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};


int main() {
    Solution sol;
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    
    int result = sol.totalFruit(fruits);
    cout << "The maximum number of fruits that can be collected is: " << result << endl;

    return 0;
}
