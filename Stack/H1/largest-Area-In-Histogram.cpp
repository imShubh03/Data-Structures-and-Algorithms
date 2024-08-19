#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/* time: O(5n)  space:O(4n)
class Solution {
public:
    vector<int> findPSE( vector<int>& arr, int n) {
        // Finding previous smaller element (PSE) indices
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If stack is empty, no smaller element found
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE( vector<int>& arr, int n) {
        // Finding next smaller element (NSE) indices
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If stack is empty, no smaller element found
            if (st.empty()) {
                ans[i] = n; // Set to n to denote the end of the array
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea( vector<int>& heights) {
        int n = heights.size();

        vector<int> pse = findPSE(heights, n);
        vector<int> nse = findNSE(heights, n);

        int maxArea = 0;
        // Find max area using PSE and NSE
        for (int i = 0; i < n; i++) {
            // Calculate width of the rectangle
            int width = nse[i] - pse[i] - 1;
            int height = heights[i];
            int area = width * height;

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            // Process the stack for elements higher than the current element
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int ele = st.top(); // Index of the height to be processed
                st.pop();

                // Determine the width of the rectangle
                int nse = i; // Next Smaller Element index
                int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element index

                // Calculate the width: (current index - previous smaller index - 1)
                int width = nse - pse - 1;
                int area = heights[ele] * width;

                // Update the maximum area found
                maxarea = max(maxarea, area);
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Process remaining elements in the stack
        while (!st.empty()) {
            int ele = st.top();
            st.pop();

            int nse = n; // If the stack is empty, set nse to the end of the array
            int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element index

            int width = nse - pse - 1;
            int area = heights[ele] * width;

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl; // Expected output: 10
    return 0;
}
