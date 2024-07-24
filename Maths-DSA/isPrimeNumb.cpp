#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
int main() {
    //Write your code here
    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;

            //for 6 6 pair we want first pair only not the second one so
            if (i != n / i) {
                cnt++;
            }
        }
    }

    if (cnt == 2) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}