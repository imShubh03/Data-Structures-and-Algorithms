#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        // Initialize all elements in left with 1
        vector<int> left(n, 1);  
        // Initialize all elements in right with 1
        vector<int> right(n, 1); 

        // Left-to-Right Pass (left array)
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                // Else part: if current rating is not greater than the previous one
                left[i] = 1;  
            }
        }

        // Right-to-Left Pass (right array)
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                // Else part: if current rating is not greater than the next one
                right[i] = 1;  
            }
        }

        // Calculate the total number of candies
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // Take the maximum of left[i] and right[i] for each student
            sum += max(left[i], right[i]);  
        }

        return sum;
    }
};


int main() {
    vector<int> ratings = {1, 3, 2, 2, 1}; 
    Solution sol;
    int result = sol.candy(ratings); 
    cout << "Total number of candies required: " << result << endl; 
    return 0;
}
