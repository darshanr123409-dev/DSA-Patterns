#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool is_check(vector<int>& arr,int i){
        if(i==arr.size()-1){
            return true;
        }
        if(arr[i]>arr[i+1]){
            return false ;
        }
        return is_check(arr,i+1);
    }
    bool isSorted(vector<int>& arr) {
        // code here
        int i=0;
        return is_check(arr,i);
        
    }
};