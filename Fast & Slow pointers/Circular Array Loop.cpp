#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Direction of starting point
            bool direction = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // Slow must stay in same direction
                if ((nums[slow] > 0) != direction)
                    break;

                // Move slow once
                int nextSlow = nextIndex(nums, slow);

                // Cycle of length 1 is invalid
                if (nextSlow == slow)
                    break;

                slow = nextSlow;


                // Fast first move
                if ((nums[fast] > 0) != direction)
                    break;

                int nextFast = nextIndex(nums, fast);

                if (nextFast == fast)
                    break;

                fast = nextFast;


                // Fast second move
                if ((nums[fast] > 0) != direction)
                    break;

                nextFast = nextIndex(nums, fast);

                if (nextFast == fast)
                    break;

                fast = nextFast;


                // Cycle found
                if (slow == fast)
                    return true;
            }
        }

        return false;
    }
};