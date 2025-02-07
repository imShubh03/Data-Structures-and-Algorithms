#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    //constructor
    Heap(){
        arr[0]=-1;
        size=0;
    }


    void insert(int val){
        size = size +1;
        int index = size;
        arr[index]= val;

        while(index >1){
            int parent = index/2;

            //max heap
            if(arr[parent]< arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        } 
    }
    void print(){
        //from index 1 not by 0 remember
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return ;
        }
        // put last node to first node
        arr[1]= arr[size];
        //decrement size so that no one will access last one
        size--;


        //take root node to correct position
        int i=1;  //root node is at 1
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i +1;

            if(leftIndex < size && arr[i]< arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                //update index
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return ;
            }
        }
    }

};
int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    // TC of insertion O(logn)

    h.deleteFromHeap();
    h.print();
    // TC of deletion O(logn)


    return 0;
}