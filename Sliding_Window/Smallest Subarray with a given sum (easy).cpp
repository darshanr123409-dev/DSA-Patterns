#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high =0;
        int n= nums.size();
        int res = INT_MAX;
        int sum=0;
        while(high<n){
            sum +=nums[high];
            while( sum >= target) {
                int length = (high -low +1);
                res = min(res,length);
                sum -= nums[low];
                low++;
            }
            high++;
        }
          // No valid subarray
        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};