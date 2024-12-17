#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string &st, string &ta, unordered_map<string, bool> &mp) {
        if (st == ta) {
            return true;
        }
        if (mp.count(st) != 0) {
            return mp[st];
        }

        int n = st.size();
        for (int i = 0; i < n; i++) {
            if (st[i] == 'L' && i > 0 && st[i - 1] == '_') {
                swap(st[i], st[i - 1]);
                if (solve(st, ta, mp)) {
                    return mp[st] = true;
                }
                swap(st[i], st[i - 1]);
            } 
            else if (st[i] == 'R' && i < n - 1 && st[i + 1] == '_') {
                swap(st[i], st[i + 1]);
                if (solve(st, ta, mp)) {
                    return mp[st] = true;
                }
                swap(st[i], st[i + 1]);
            }
        }
        return mp[st] = false;
    }

    bool canChange(string start, string target) {
        unordered_map<string, bool> mp;
        return solve(start, target, mp);
    }
};

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip blanks in both strings
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If one reaches the end while the other doesn't
            if (i == n || j == n) {
                return i == n && j == n;
            }

            // Check if characters mismatch
            if (start[i] != target[j]) {
                return false;
            }

            // 'L' should not move to the right, 'R' should not move to the left
            if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                return false;
            }

            // Move both pointers
            i++;
            j++;
        }
        return true;
    }
};

int main() {
    string start, target;
    cin >> start;
    cin >> target;

    Solution sol;
    if (sol.canChange(start, target)) {
        cout << "Yes, target can be obtained from start.\n";
    } else {
        cout << "No, target cannot be obtained from start.\n";
    }
    return 0;
}
