#include<iostream>
#include<cmath>
using namespace std;

int main(){
    
    int arr1[5]={1,4,6,4,9};
    int arr2[5]={2,4,3,6,7};
    for(int i=0;i<5;i++){
        int element=arr1[i];
        for(int j=0;j<5;j++){
            if(element==arr2[j]){
                cout<<element<<endl;
                arr2[j]=-363487;//so that repeated num in array doesnt get interse again with secon array
            }

        }
        
    }

    return 0;
}