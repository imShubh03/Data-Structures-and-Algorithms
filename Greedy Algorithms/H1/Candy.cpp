#include<bits/stdc++.h>
using namespace std;

/* brute : time:O(3n) space:O(2n)
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
*/

/* time: O(2n) space:O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> left(n, 1);  // Initialize all elements in left with 1
        
        // Left-to-right pass (left array)
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Right-to-left pass and calculate sum in the same loop
        int sum = left[n - 1];  // Start with the last element of the left array
        int right = 1;  // Initialize for the right-to-left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            sum += max(left[i], right);  // Take the maximum of left and right
        }

        return sum;
    }
};
*/

// optimised 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n  = ratings.size();
        int sum =1;
        int i =1;
        while(i<n){
            // flat surface
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            // increasing slope
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            // decreasing slope
            int down = 1;
            while(i<n && ratings[i]< ratings[i-1]){
                sum += down;
                i++;
                down++;
            }

            // decreasing over
            if(down > peak){
                sum += (down - peak);
            }
        }
        return sum;
    }
};

int main() {
    vector<int> ratings = {1,0,2}; 
    Solution sol;
    int result = sol.candy(ratings); 
    cout << "Total number of candies required: " << result << endl; 
    return 0;
}
