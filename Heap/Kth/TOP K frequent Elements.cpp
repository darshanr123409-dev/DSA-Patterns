#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &arr, int k)
    {
        int n = arr.size();
        // Min heap: {frequency, element}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;
        unordered_map<int, int> f;
        for (auto it : arr)
        {
            f[it]++;
        }
        for (auto i : f)
        {
            int elem = i.first;
            int freq = i.second;
            pair<int, int> cur({freq, elem});
            if (pq.size() < k)
            {
                pq.push(cur);
                continue;
            }
            if (cur.first < pq.top().first)
            {
                continue;
            }
            pq.pop();
            pq.push(cur);
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
};