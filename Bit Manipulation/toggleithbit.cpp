#include<bits/stdc++.h>
using namespace std;

int togglebit(int num,int i){
    int mask = 1 << i;
    return num ^ mask;

}

int main(){
    int num, i;
    cout << "Enter the number (n): ";
    cin >> num;
    cout << "Enter the bit position (i): ";
    cin >> i;
    int result = togglebit(num, i);
    
    cout << "Number after toggling the " << i << "th bit: " << result << endl;
    
    return 0;
}