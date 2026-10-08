#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int res =-1;
        int low =0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = ( low + high )/2;
            if(arr[mid]>arr[mid+1]){
                high = mid-1;
                res = mid;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};