/*
1 
0 1 
1 0 1 
0 1 0 1
*/

#include <iostream>
using namespace std;

void nBinaryTriangle(int n) {
    int start =-1;
    for(int i = 1;i<=n;i++){
        start = (i%2 == 0) ? 0 : 1;
        for(int j =1;j<=i;j++){
            cout<<start<<" ";
            // to flip numbers
            start = 1 - start;
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    nBinaryTriangle(n);
    return 0;
}
