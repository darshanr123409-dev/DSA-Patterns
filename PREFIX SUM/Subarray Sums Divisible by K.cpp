#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          int n = nums.size();

        unordered_map<int, int> prefixSum;

        int sum = 0;
        int count = 0;

        prefixSum[0] = 1;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            // Normalize remainder to [0, k - 1]
            int rem = (sum % k + k) % k;
            
            if (prefixSum.find(rem) != prefixSum.end()) {
                count += prefixSum[rem];
            }
            prefixSum[rem]++;
        }

        return count;

    }
};