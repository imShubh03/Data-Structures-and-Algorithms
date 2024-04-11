#include <iostream>
using namespace std;

int removeRightmostSetBit(int num) {
    return num & (num - 1);
}

int main() {
    int num, i;
    cout << "Enter the number (n): ";
    cin >> num;
    int result = removeRightmostSetBit(num);
    
    cout << "Number after removing the rightmost set bit: " << result << endl;
    
    return 0;
}
