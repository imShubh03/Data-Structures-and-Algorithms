#include <iostream>
using namespace std;

int setBit(int num, int i) {
    
    int mask = 1 << i;
    return num | mask;
}

int main() {
    int num, i;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the position of bit to set: ";
    cin >> i;
    int result = setBit(num, i);
    
    cout << "Number after setting the " << i << "th bit: " << result << endl;
    
    return 0;
}
