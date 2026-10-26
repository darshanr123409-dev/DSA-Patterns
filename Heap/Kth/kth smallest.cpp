
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         priority_queue<int> pq;
         int i;
         for(int i=0 ;i<k ;i++){
             pq.push(arr[i]);
         }
         for(i=k ; i<arr.size() ; i++){
            if(arr[i]>=pq.top()){
                continue;
            }   
            pq.pop();
            pq.push(arr[i]);
         
             
    }
         return pq.top();
    }
};