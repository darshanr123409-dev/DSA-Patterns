#include <bits/stdc++.h>
using namespace std;

vector<int> Two_sum(vector<int>& arr, int target) {
    int n = arr.size();

    vector<pair<int, int>> nums;

    // Store: {value, original index}
    for (int i = 0; i < n; i++) {
        nums.push_back({arr[i], i});
    }

    sort(nums.begin(), nums.end());

    int i = 0;
    int j = n - 1;

    while (i < j) {
        int sum = nums[i].first + nums[j].first;

        if (sum == target) {
            return {nums[i].second, nums[j].second};
        }
        else if (sum < target) {
            i++;
        }
        else {
            j--;
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {3, 2, 4};
    int target = 6;

    vector<int> ans = Two_sum(arr, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}