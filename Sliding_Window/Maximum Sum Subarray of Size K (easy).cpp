#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0;
        int high = k - 1;

        int sum = 0;
        int res = INT_MIN;

        // Calculate first window
        for (int i = low; i <= high; i++) {
            sum += arr[i];
        }

        // Slide the window
        while (high < n) {

            res = max(res, sum);

            // Remove the first element
            sum -= arr[low];

            // Move window
            low++;
            high++;

            // Add the new element
            if (high < n) {
                sum += arr[high];
            }
        }

        return res;
    }
};