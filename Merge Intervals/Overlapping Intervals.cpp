#include<bits/stdc++.h>
using namespace std;

// Function to check if any two intervals
// in the given list intersect with each other
bool isIntersect(vector<vector<int>> intervals) {
    int n = intervals.size();

    // sort the intervals based on the starting time
    sort(intervals.begin(), intervals.end());

    // check if any of the interval 
    // intersects with its previous
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= intervals[i - 1][1])
            return true;
    }

    return false;
}