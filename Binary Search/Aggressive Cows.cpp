#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& stalls, int k, int mid) {
        int cows = 1;
        int pre_cows = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            int dist = stalls[i] - pre_cows;

            if (dist < mid) {
                continue;
            }

            cows++;
            pre_cows = stalls[i];

            if (cows >= k) {
                return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int low = 1;
        int high = arr[n - 1] - arr[0];
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(arr, k, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};
