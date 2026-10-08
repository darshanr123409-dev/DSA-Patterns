#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        
    
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is on the right
                low = mid + 1;
            }
            else {
                // mid can be the minimum
                high = mid;
            }
        }

        return low;
    }
};