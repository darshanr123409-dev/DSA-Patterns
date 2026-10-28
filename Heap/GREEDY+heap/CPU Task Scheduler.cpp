#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        for (char task : tasks) {
            freq[task]++;
            free[task] = 1;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        int seat = 1;

        while (!pq.empty()) {
            vector<pair<int, char>> pulled;
            bool executed = false;

            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();

                int remaining = p.first;
                char task = p.second;

                if (free[task] <= seat) {
                    executed = true;

                    if (remaining > 1) {
                        pq.push({remaining - 1, task});
                        free[task] = seat + n + 1;
                    }

                    break;
                } else {
                    pulled.push_back(p);
                }
            }

            for (auto p : pulled) {
                pq.push(p);
            }

            seat++;
        }

        return seat - 1;
    }
};