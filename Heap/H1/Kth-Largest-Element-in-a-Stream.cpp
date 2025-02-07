#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    vector<int> stream; // To store elements in the stream
    int k;

    // Constructor: Initializes the stream and the value of k
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        stream = nums; // Store the initial stream
    }
    
    // Add method: Adds a new element to the stream and returns the Kth largest element
    int add(int val) {
        stream.push_back(val); // Add the new value to the stream
        
        // Sort the stream in descending order
        sort(stream.rbegin(), stream.rend());

        // Return the Kth largest element (since it's sorted in descending order)
        return stream[k - 1];
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest obj(3, nums);
    
    // Add elements and print the Kth largest element
    cout << obj.add(3) << endl;  // Output: 4
    cout << obj.add(5) << endl;  // Output: 5
    cout << obj.add(10) << endl; // Output: 5
    cout << obj.add(9) << endl;  // Output: 8
    cout << obj.add(4) << endl;  // Output: 8

    return 0;
}
