#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int findPeakElement(vector<int>& nums) {
        // Set left and right bounds
        int n=nums.size();
        if(n==1)    return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int low = 1, high = n - 2;

        // Binary search loop
        while (low <= high) {
            // Find mid point
            int mid = (low + high) / 2;

            // If mid element is greater than next
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]) {
                // Move to left half
                return mid;
                
            } else if(nums[mid] > nums[mid-1]) {
                // Move to right half
                low = mid + 1;
            }
            else if (nums[mid]>nums[mid+1]){
                high = mid-1; 
            }
            else {
                low = mid+1;
            }
        }
        // Return peak index
        return -1;
    }
};
        
