#include <iostream>
using namespace std;

bool isPalindrome(const string &str, int start, int end) {
    // Base case: if start meets or exceeds end, it's a palindrome
    if (start >= end) return true;  
    // If characters at start and end are different, it's not a palindrome
    if (str[start] != str[end]) return false;  
    // Recursive call with updated indices
    return isPalindrome(str, start + 1, end - 1);  
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "The string  "<< str << "is a palindrome." << endl;
    } else {
        cout << "The string "<< str << " is not a palindrome." << endl;
    }

    return 0;
}
