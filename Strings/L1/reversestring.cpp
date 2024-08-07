#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& ch) {
        int n = ch.size();
        int low = 0;
        int high = n - 1;
        while (low < high) {  // Correct condition to avoid swapping in the middle
            swap(ch[low++], ch[high--]);
        }
    }
};

int main() {
    int size;
    cout << "Enter size: " << endl;
    cin >> size;

    vector<char> ch(size);
    cout << "Enter characters: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> ch[i];
    }

    Solution sol;
    sol.reverseString(ch);  // No need to assign, as it modifies in place

    cout << "Reversed string: ";
    for (char c : ch) {
        cout <<c;
    }
    cout << endl;

    return 0;
}
