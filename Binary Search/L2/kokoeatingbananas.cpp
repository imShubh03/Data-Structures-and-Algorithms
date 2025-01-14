#include <bits/stdc++.h>
using namespace std;

/* brute force TC:O(maxele * n)
class Solution {
public:
    // Function to calculate the total hours required to eat all bananas at a specific hourly rate
    int func(vector<int>& piles, int hrly) {
        int totalHrs = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalHrs += (piles[i] + hrly - 1) / hrly; // Corrected to use integer division for ceiling
        }
        return totalHrs;
    }

    // Brute-force approach to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEl = *max_element(piles.begin(), piles.end()); // Maximum bananas in any pile

        // Check every speed from 1 to maxEl
        for (int i = 1; i <= maxEl; i++) {
            int reqTime = func(piles, i); // Calculate required time for speed i

            if (reqTime <= h) {
                return i; // Return the first speed that satisfies the condition
            }
        }

        return -1; // In case no speed satisfies the condition (should not occur in valid inputs)
    }
};
*/


class Solution{
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }

    int calcTotalHrs(vector<int> &piles, int hourly){
        int totalHrs = 0;
        int size = piles.size();
        for (int i = 0; i < size; i++)
        {
            totalHrs += ceil(double(piles[i]) / double(hourly));
        }
        return totalHrs;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h){
        int low = 1; // Koko needs to eat at least one pile per hour
        int high = findMax(piles);
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            int totalHrs = calcTotalHrs(piles, mid);

            if (totalHrs <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    return 0;
}
