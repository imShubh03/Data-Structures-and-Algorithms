#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int findMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }

    int calcTotalHrs(vector<int> &piles, int hourly)
    {
        int totalHrs = 0;
        int size = piles.size();
        for (int i = 0; i < size; i++)
        {
            totalHrs += ceil(double(piles[i]) / double(hourly));
        }
        return totalHrs;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
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
