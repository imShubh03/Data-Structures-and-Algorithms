#include <bits/stdc++.h>
using namespace std;

/* TC:O(max-sum) * O(n)
class Solution{
public:
    int func(vector<int> &weights, int cap) {
        int load = 0;
        int days = 1;

        for(int i =0; i<weights.size(); i++) {
            if(load + weights[i] > cap) {
                //move to next day
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days) {
        int n = weights.size();

        int mincap = *max_element(weights.begin(), weights.end());
        int maxcap = accumulate(weights.begin(), weights.end(), 0);

        for(int i = mincap; i<= maxcap; i++) {
            int daysReq = func(weights, i);

            if(daysReq <= days) {
                return i;
            }
        }
        return -1;
    }
};
*/


class Solution{
public:
    int func(vector<int> &weights, int cap) {
        int load = 0;
        int days = 1;

        for(int i =0; i<weights.size(); i++) {
            if(load + weights[i] > cap) {
                //move to next day
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;

        while(low <= high) {
            int mid = (low + high)/2;

            int daysReq = func(weights, mid);

            if(daysReq <= days) {
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


int main() {
    int n, days;
    cin>> n >> days;

    vector<int> weights(n);

    for(int i =0; i<n; i++) {
        cin>> weights[i];
    }

    Solution sol;

    int ans = sol.shipWithinDays(weights, days);
    cout << ans;


    return 0;
}