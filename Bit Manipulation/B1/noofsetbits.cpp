#include<bits/stdc++.h>
using namespace std;

/*
int countBits(int num){
    int cnt =0;
    while(num > 0){ 
        if(num % 2 == 1){
            cnt++;
        }
        num = num/2;
    }
    return cnt;
}
*/
int countBits(int num){
    int cnt = 0;
    while(num > 0){ 
        if(num & 1){ 
            cnt++;
        }
        num = num >> 1;
    }
    return cnt;
}

int main(){
    int num;
    cout << "Enter the number (num): ";
    cin >> num;
    int result = countBits(num);
    
    cout << "Number of set bits: " << result << endl;
    return 0;
}
