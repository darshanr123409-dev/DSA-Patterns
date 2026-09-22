#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;

        // prefix sum 0 exists before index 0
        mp[0] = -1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                sum--;
            else
                sum++;

            // Same prefix sum already seen
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }
            else {
                // Store only the first occurrence
                mp[sum] = i;
            }
        }

        return ans;
    }
};