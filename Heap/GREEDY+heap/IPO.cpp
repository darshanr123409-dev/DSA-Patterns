#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int wallet,
                             vector<int> &profits,
                             vector<int> &capital)
    {
        int n = profits.size();

        vector<pair<int, int>> project;

        // Step 1: Store {capital, profit}
        for (int i = 0; i < n; i++)
        {
            project.push_back({capital[i], profits[i]});
        }

        // Step 2: Sort projects by required capital
        sort(project.begin(), project.end());

        int i = 0;

        // Max heap: highest profit comes first
        priority_queue<int> pq;

        while (k--)
        {
            // Step 3: Find all affordable projects
            while (i < n)
            {
                if (project[i].first > wallet)
                {
                    break;
                }

                pq.push(project[i].second);
                i++;
            }

            // Step 4: No affordable project available
            if (pq.empty())
            {
                return wallet;
            }

            // Step 5: Select the highest-profit project
            wallet += pq.top();
            pq.pop();
        }

        return wallet;
    }
};