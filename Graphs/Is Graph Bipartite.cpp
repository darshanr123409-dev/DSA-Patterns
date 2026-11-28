#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool res = true;

    void dfa(vector<vector<int>>& arr, int node, int c,
             vector<int>& colors) {

        colors[node] = c;

        for(int i = 0; i < arr[node].size(); i++) {

            int neigh = arr[node][i];

            if(colors[neigh] != -1 && colors[neigh] == c) {
                res = false;
                return;
            }

            if(colors[neigh] == -1) {
                dfa(arr, neigh, 1-c, colors);
            }

            if(res == false) {
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> colors(n, -1);
        res = true;

        for(int i = 0; i < n; i++) {

            if(colors[i] == -1) {
                dfa(graph, i, 0, colors);
            }

            if(res == false) {
                return false;
            }
        }

        return res;
    }
};
