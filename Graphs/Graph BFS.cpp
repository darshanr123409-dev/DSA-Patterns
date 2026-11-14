#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here

        int V = adj.size();
        vector<int> bfsTraversal;
        vector<bool> visited(V, false);
        queue<int> q;

        // Start traversal from vertex 0
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfsTraversal.push_back(node);

            // Traverse all neighbors of the current node
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfsTraversal;
    }
};