#include <iostream>
using namespace std;

// USING LEFT SHIFT 
bool isKthBitSet(int n, int k)
{
    // Check if the kth bit is set in n
    if ((n & (1 << (k))) != 0) {
        return true;
    } else {
        return false;
    }
}

//USING RIGHT SHIFT
bool isKthBitSet(int n, int k)
{
    // Check if the kth bit is set in n
    if (((n >> (k - 1)) & 1) != 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
    int n, k;
    cout << "Enter the number (n): ";
    cin >> n;
    cout << "Enter the bit position (k): ";
    cin >> k;

    if (isKthBitSet(n, k)) {
        cout << "The " << k << "th bit is set in " << n << endl;
    } else {
        cout << "The " << k << "th bit is not set in " << n << endl;
    }

    return 0;
}
