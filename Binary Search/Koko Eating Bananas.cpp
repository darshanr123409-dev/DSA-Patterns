#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long n = 0;

        for (auto bananas : piles) {
            n += bananas / speed;

            if (bananas % speed != 0) {
                n++;
            }
        }

        return n;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxPile;
        int ans = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
