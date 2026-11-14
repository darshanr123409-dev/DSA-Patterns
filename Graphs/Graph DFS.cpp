#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void check_dfa(vector<vector<int>>& adj,int node ,
    vector<int>& res ,vector<bool>& visited ){
        res.push_back(node);
        visited[node]=true;
        for(int i=0 ; i < adj[node].size(); i++){
            int near = adj[node][i];
            if(!visited[near]){
                check_dfa(adj,near,res,visited);
            }
        }
        return ;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> res;
        vector<bool> visi(n,0);
        check_dfa(adj,0,res,visi);
        return res; 
    }
};
