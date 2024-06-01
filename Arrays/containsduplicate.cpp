#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.find(num) != seen.end())
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;

    vector<int> nums(n); // Resizing the vector to hold n elements

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;

    cout << "Contains duplicate: " << (sol.containsDuplicate(nums) ? "Yes" : "No") << endl;

    return 0;
}
