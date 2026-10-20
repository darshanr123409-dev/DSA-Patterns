#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    // Check if we can split array into <= k subarrays
    // such that each subarray sum <= maxSum
    bool canSplit(vector<int>& nums, int k, long long maxSum) {

        int count = 1;
        long long currentSum = 0;

        for (int num : nums) {

            if (currentSum + num <= maxSum) {
                currentSum += num;
            }
            else {
                count++;
                currentSum = num;
            }
        }

        return count <= k;
    }


    int splitArray(vector<int>& nums, int k) {

        // Minimum possible answer
        long long low = *max_element(nums.begin(), nums.end());

        // Maximum possible answer
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                // Possible answer
                // Try to find smaller maximum sum
                high = mid - 1;
            }
            else {
                // Need a bigger maximum sum
                low = mid + 1;
            }
        }

        return low;
    }
};