#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Count the frequency of each character
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        // Priority queue to store pairs of {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        // Construct the result string from the priority queue
        string ans = "";
        while (!pq.empty()) {
            int n = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            while (n-- > 0) {
                ans += c;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string input = "tree";
    string result = sol.frequencySort(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;
    return 0;
}
