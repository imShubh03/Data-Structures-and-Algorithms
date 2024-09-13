#include <bits/stdc++.h>
using namespace std;

// Define the Item class
class Item {
public:
    int value;
    int weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items based on value-to-weight ratio
bool comparator(const Item& a, const Item& b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int capacity, Item arr[], int n) {
        // Sort items by value-to-weight ratio in descending order
        sort(arr, arr + n, comparator);
        
        double totalValue = 0.0; // Initialize total value
        int remainingCapacity = capacity; // Initialize remaining capacity
        
        for (int i = 0; i < n; i++) {
            if (remainingCapacity <= 0) break; // Stop if the knapsack is full

            if (arr[i].weight <= remainingCapacity) {
                // If the whole item can be added
                totalValue += arr[i].value;
                remainingCapacity -= arr[i].weight;
            } else {
                // Add fractional part of the item
                totalValue += arr[i].value * ((double)remainingCapacity / arr[i].weight);
                remainingCapacity = 0; // Knapsack is now full
            }
        }
        
        return totalValue;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    
    int capacity = 50; // Capacity of the knapsack
    Item arr[] = { Item(60, 10), Item(100, 20), Item(120, 30) };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Maximum value in the knapsack = " << sol.fractionalKnapsack(capacity, arr, n) << endl;
    
    return 0;
}
