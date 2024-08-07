#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int isValid(string str) {
        string temp = "";
        int cntdots = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '.') {
                temp += str[i];
            } else {
                if (temp.empty() || temp.size() > 3 || stoi(temp) > 255 || (temp.size() > 1 && temp[0] == '0')) {
                    return 0; // Invalid segment
                }
                temp = "";
                cntdots++;
            }
        }

        // Final segment check
        if (temp.empty() || temp.size() > 3 || stoi(temp) > 255 || (temp.size() > 1 && temp[0] == '0')) {
            return 0;
        }

        // There should be exactly 3 dots in a valid IP address
        if (cntdots != 3) return 0;

        return 1;
    }
};

int main() {
    Solution sol;

    // Test cases
    string ip1 = "192.168.1.1";
    string ip2 = "255.255.255.255";
    string ip3 = "256.100.50.25"; // Invalid
    string ip4 = "123.045.067.089"; // Invalid
    string ip5 = "1.1.1.1.1"; // Invalid

    cout << "IP Address: " << ip1 << " is " << (sol.isValid(ip1) ? "Valid" : "Invalid") << endl;
    cout << "IP Address: " << ip2 << " is " << (sol.isValid(ip2) ? "Valid" : "Invalid") << endl;
    cout << "IP Address: " << ip3 << " is " << (sol.isValid(ip3) ? "Valid" : "Invalid") << endl;
    cout << "IP Address: " << ip4 << " is " << (sol.isValid(ip4) ? "Valid" : "Invalid") << endl;
    cout << "IP Address: " << ip5 << " is " << (sol.isValid(ip5) ? "Valid" : "Invalid") << endl;

    return 0;
}
