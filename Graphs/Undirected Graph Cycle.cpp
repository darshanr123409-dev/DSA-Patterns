#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool cycle = false;

    void dfa_check(vector<vector<int>>& arr, int n, int node,
                   int parent, vector<bool>& visited) {

        visited[node] = 1;

        for(int i = 0; i < arr[node].size(); i++) {
            int neigh = arr[node][i];

            if(visited[neigh] == 1 && neigh != parent) {
                cycle = true;
                return;
            }

            if(visited[neigh] == 0) {
                dfa_check(arr, n, neigh, node, visited);
            }
        }
        return;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<bool> visited(n, 0);
        cycle = false;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                dfa_check(adj, n, i, -1, visited);
            }

            if(cycle == true) {
                return true;
            }
        }

        return false;
    }
};
