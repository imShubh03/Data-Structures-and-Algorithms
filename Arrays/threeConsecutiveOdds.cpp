#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            { // if its odd then increment
                count++;
                if (count == 3)
                {
                    return true;
                }
            }
            else
            { // if even then reset count
                count = 0;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cout << "enter n" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "enter elem in arrays" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    bool ans = sol.threeConsecutiveOdds(arr);

    if (ans)
    {
        cout << "its true" << endl;
    }
    else
    {
        cout << "its false" << endl;
    }

    return 0;
}