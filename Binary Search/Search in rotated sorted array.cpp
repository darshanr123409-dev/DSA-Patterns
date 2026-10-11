#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low =0;
        int high = arr.size();
        int n = arr.size();
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[mid]> arr[n-1]){
                if(arr[mid] < target){
                    low = mid+1;
                }
                else {
                    if(arr[0]>target){
                        low = mid+1;
                    }
                    else {
                        high = mid-1;
                    }
                }
            }
            else {
                if(arr[mid] > target){
                    high = mid-1;
                }
                else {
                    if(arr[n-1]<target){
                        high = mid-1;
                    }
                    else {
                        low = mid+1;
                    }
                }
            }
        }
        return -1;
    }
};