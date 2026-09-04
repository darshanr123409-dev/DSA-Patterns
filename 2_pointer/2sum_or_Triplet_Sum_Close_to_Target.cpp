#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Store minimum difference found
        int diff = INT_MAX;

        // Store the closest sum
        int res_sum = 0;

        // Fix one element
        for (int i = 0; i < n - 2; i++) {
            
            int left = i + 1;
            int right = n - 1;

            // Two pointer approach
            while (left < right) {
                
                int total = nums[i] + nums[left] + nums[right];

                int d = abs(target - total);

                // Update closest sum
                if (diff > d) {
                    diff = d;
                    res_sum = total;
                }

                // Exact match
                if (total == target) {
                    return res_sum;
                }

                // Move pointers
                if (total < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res_sum;
    }
};