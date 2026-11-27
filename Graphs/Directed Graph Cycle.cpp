#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool cycle = false;

    void dfs_check(vector<vector<int>>& arr, int n, int node,
                   vector<bool>& visited, vector<bool>& path) {

        path[node] = 1;
        visited[node] = 1;

        for(int j = 0; j < arr[node].size(); j++) {
            int neigh = arr[node][j];

            if(visited[neigh] == 1 && path[neigh] == 1) {
                cycle = true;
            }

            if(visited[neigh] == 0) {
                dfs_check(arr, n, neigh, visited, path);
            }
        }

        path[node] = 0;
        return;
    }

    bool isCyclic(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<bool> visited(n, 0);
        vector<bool> path(n, 0);

        cycle = false;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs_check(adj, n, i, visited, path);
            }
        }

        return cycle;
    }
};