#include <iostream>
using namespace std;

// TC : O(log base 10(N))
class DigitCounter {
public:
    int countDigits(int n) {
        int cnt = 0;
        while (n != 0) {
            cnt++;
            n = n / 10;
        }
        return cnt;
    }
};

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    DigitCounter dc;
    int result = dc.countDigits(n);
    cout << "Number of digits: " << result << endl;

    return 0;
}
