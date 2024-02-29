#include<iostream>
#include<cmath>
using namespace std;
int unique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        //we know XOR properties
        // a^a=0 and 0^a=a
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[6]={1,5,8,5,1};
    unique(arr,5);
    return 0;
}