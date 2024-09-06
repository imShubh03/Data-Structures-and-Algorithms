#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for (int bill : bills) {
            if (bill == 5) {
                fives++;  // Collect a $5 bill
            } else if (bill == 10) {
                if (fives == 0) {
                    return false;  // Cannot give $5 change
                }
                fives--;  // Use one $5 bill as change
                tens++;   // Collect a $10 bill
            } else { // bill == 20
                // Try to give one $10 and one $5 as change first
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } 
                // If no $10 bill is available, try to give three $5 bills
                else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;  // Cannot give change
                }
            }
        }
        return true;  // Successfully provided change for all customers
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << " ans " << (solution.lemonadeChange(bills1) ? "true" : "false") << endl;

    return 0;
}
