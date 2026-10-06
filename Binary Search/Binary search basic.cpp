#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& nums, int low, int high, int target) {

        // Base Case
        if (low > high)
            return -1;

        // Find middle index
        int mid = low + (high - low) / 2;

        // Target found
        if (nums[mid] == target)
            return mid;

        // Search right half
        else if (target > nums[mid])
            return binarySearch(nums, mid + 1, high, target);

        // Search left half
        return binarySearch(nums, low, mid - 1, target);
    }

    int search(vector<int>& nums, int target) {

        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};