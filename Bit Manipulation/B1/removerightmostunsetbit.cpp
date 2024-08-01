#include <iostream>
using namespace std;

int remove(int num) {

    return num & (num + 1);
}

int main() {
    int num, i;
    cout << "Enter the number (n): ";
    cin >> num;
    int result = remove(num);
    
    cout << "Number after removing the rightmost unset bit: " << result << endl;
    
    return 0;
}
