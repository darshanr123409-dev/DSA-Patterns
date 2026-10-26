#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void combi(int index, vector<int>& candidates, int target,
               vector<int>& current, vector<vector<int>>& ans) {

        // Base case
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        // Pick the current element
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            // Same index because we can reuse the same element
            combi(index, candidates, target - candidates[index], current, ans);

            current.pop_back(); // backtrack
        }

        // Don't pick the current element
        combi(index + 1, candidates, target, current, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        combi(0, candidates, target, current, ans);

        return ans;
    }
};