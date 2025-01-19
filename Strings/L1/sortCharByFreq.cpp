#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        // Vector to store frequency of each character
        vector<pair<char, int>> freq(123);

        // Initialize frequency vector
        for (int i = 0; i < 123; i++) {
            freq[i] = {char(i), 0};
        }

        // Count frequency of each character
        for (char &ch : s) {
            freq[ch].second++;
        }

        // Lambda function to sort based on frequency
        auto lambda = [](pair<char, int> &p1, pair<char, int> &p2) {
            return p1.second > p2.second; // Fix syntax error here
        };

        // Sort by frequency in descending order
        sort(freq.begin(), freq.end(), lambda);

        // Build the resulting string
        string res = "";

        for (int i = 0; i < 123; i++) {
            if (freq[i].second > 0) {
                res += string(freq[i].second, freq[i].first); // Append characters frequency times
            }
        }
        return res;
    }
};
*/

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
