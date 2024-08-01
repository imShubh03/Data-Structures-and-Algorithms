#include<bits/stdc++.h>
using namespace std;

int clearBit(int num, int i) {
    // Left shift 1 by i positions to create a mask with only the ith bit set
    int mask = ~(1 << i);
    // Perform bitwise AND with the mask to clear the ith bit
    return num & mask;
}

int main(){
    int num, i;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the position of bit to clear: ";
    cin >> i;
    int result = clearBit(num, i);
    
    cout << "Number after clearing the " << i << "th bit: " << result << endl;
    
    return 0;
}
