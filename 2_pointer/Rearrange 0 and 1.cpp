#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int low=0;
        int mid=n-1;
        while(low<=mid){
            if(arr[low]==0){
                low++;
            }
            else {
                swap(arr[low],arr[mid]);
                mid--;
            }
        }
        
    }
};