#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void sum(vector<int>& arr, int n, int i,
             vector<int>& dairy, int s,
             vector<vector<int>>& res, int target) {

        if(i == n) {
            if(s == target) {
                res.push_back(dairy);
            }
            return;
        }

        // Nahi lena hai
        sum(arr, n, i + 1, dairy, s, res, target);

        // Lena hai
        if(arr[i] + s <= target) {

            dairy.push_back(arr[i]);
            s += arr[i];

            sum(arr, n, i, dairy, s, res, target);

            dairy.pop_back();
            s -= arr[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        int i = 0;
        int n = candidates.size();

        vector<int> dairy;
        vector<vector<int>> res;

        int s = 0;

        sum(candidates, n, i, dairy, s, res, target);

        return res;
    }
};
