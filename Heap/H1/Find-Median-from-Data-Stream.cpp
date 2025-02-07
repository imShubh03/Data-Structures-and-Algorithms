#include <bits/stdc++.h>
using namespace std;

/*
class MedianFinder {
private:
    vector<int> arr; 
public:
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(), arr.end()); // Sort after each insertion
    }

    double findMedian() {
        int n = arr.size();
        if (n % 2 == 1) return arr[n / 2];
        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    }
};
*/

class MedianFinder {
public:
    priority_queue<int > left_maxHeap;
    priority_queue<int, vector<int>, greater<int>>right_minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_maxHeap.empty() || num < left_maxHeap.top()){
            left_maxHeap.push(num);
        }
        else{
            right_minHeap.push(num);
        }
        // Balance the heaps: left_maxHeap size should be either equal or 1 greater than right_minHeap
        //always maintain left_maxHeap size 1 greater than right_minHeap  OR boths size should be same only

        if(abs((int)left_maxHeap.size() - (int)right_minHeap.size()) >  1){
            right_minHeap.push(left_maxHeap.top());
            left_maxHeap.pop();
        }
        else if(left_maxHeap.size() < right_minHeap.size()){
            left_maxHeap.push(right_minHeap.top());
            right_minHeap.pop();
        }
    }
    
    double findMedian() {
        if(right_minHeap.size() == left_maxHeap.size()){
            //even numb of elem
            double ans = (left_maxHeap.top()+ right_minHeap.top())/2.0;
            return ans;
        }

        return left_maxHeap.top();
    }
};


int main() {
    MedianFinder mf;
    int n, num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        mf.addNum(num);
        cout << num << ": " << mf.findMedian() << endl;
    }

    return 0;
}
