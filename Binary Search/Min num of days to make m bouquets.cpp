#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Check if we can make m bouquets by given day
    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int cnt = 0;        // Consecutive bloomed flowers
        int bouquets = 0;   // Number of bouquets

        for (int i = 0; i < bloomDay.size(); i++) {

            // Flower has bloomed
            if (bloomDay[i] <= day) {
                cnt++;

                // We got k consecutive flowers
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            }
            else {
                // Consecutive sequence broken
                cnt = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        // Total flowers required
        long long totalFlowers = 1LL * m * k;

        // Not enough flowers
        if (totalFlowers > bloomDay.size()) {
            return -1;
        }

        // Minimum and maximum bloom day
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        // Binary search on days
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {

                // Possible to make bouquets
                // Try to find a smaller day
                ans = mid;
                high = mid - 1;
            }
            else {

                // Not possible
                // Need more days
                low = mid + 1;
            }
        }

        return ans;
    }
};