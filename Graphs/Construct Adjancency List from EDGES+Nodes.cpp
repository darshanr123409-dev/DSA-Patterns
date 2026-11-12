#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<vector<int>>& edges) {
        // code here
        // int n = edges.size();
        vector<vector<int>> adj(V);
        for(int i=0 ; i<edges.size() ; i++ ){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
            
        }
        return adj;
    }
};