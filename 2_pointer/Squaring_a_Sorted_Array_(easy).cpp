#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos, neg;

        // Separate negative and positive numbers
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }

        // Case 1: No negative numbers
        if(neg.size() == 0) {

            for(int i = 0; i < pos.size(); i++) {
                pos[i] = pos[i] * pos[i];
            }

            return pos;
        }

        // Case 2: No positive numbers
        if(pos.size() == 0) {

            for(int i = 0; i < neg.size(); i++) {
                neg[i] = neg[i] * neg[i];
            }

            reverse(neg.begin(), neg.end());

            return neg;
        }

        // Square negative numbers
        for(int i = 0; i < neg.size(); i++) {
            neg[i] = neg[i] * neg[i];
        }

        // Negative numbers become descending after squaring,
        // so reverse them
        reverse(neg.begin(), neg.end());

        // Square positive numbers
        for(int i = 0; i < pos.size(); i++) {
            pos[i] = pos[i] * pos[i];
        }

        int i = 0;
        int j = 0;
        int index = 0;

        int num = neg.size();
        int m = pos.size();

        vector<int> ans(num + m);

        // Merge two sorted arrays
        while(i < num && j < m) {

            if(neg[i] <= pos[j]) {
                ans[index] = neg[i];
                i++;
            }
            else {
                ans[index] = pos[j];
                j++;
            }

            index++;
        }

        // Remaining negative-square elements
        while(i < num) {
            ans[index] = neg[i];
            i++;
            index++;
        }

        // Remaining positive-square elements
        while(j < m) {
            ans[index] = pos[j];
            j++;
            index++;
        }

        return ans;
    }
};