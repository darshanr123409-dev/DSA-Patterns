#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    vector<int> check_topological(vector<vector<int>>& edges, int n) {
        vector<vector<int>> arr(n);
        vector<int> index_degree(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dest = edges[i][1];

            arr[src].push_back(dest);
            index_degree[dest]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(index_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(int j = 0; j < arr[node].size(); j++) {
                int neigh = arr[node][j];

                index_degree[neigh]--;

                if(index_degree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return res;
    }

    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();

        return check_topological(adj, n);
    }
};
