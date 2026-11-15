#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int x[4] = { -1, 1, 0, 0};
    int y[4] = { 0, 0, -1, 1};
    bool valid(int i,int j ,int n,int m){
        if(i<0 or i>=n or j<0 or j>=m){
            return false;;
        }
        return true;
    }
    void icelands(vector<vector<char>>& arr , int n ,int m,int i,int j,vector<vector<bool>>& visited){
        visited[i][j] = true;
        for(int k =0 ; k<4 ; k++){
            int row = i + x[k]; 
            int col = j + y[k];
            if(valid(row,col,n,m) && arr[row][col] == '1' && !visited[row][col]){
                icelands(arr, n, m ,row ,col,visited);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid.empty() || grid[0].empty()) return 0;
        int res =0;
        int i,j;
        vector<vector<bool>> visited(n);
        for(auto i =0 ;i<n ;i++){
            vector<bool> temp(m ,0);
            visited[i] = temp; 
        }
        for(int i =0 ; i<n ;i++){
            for(int j =0 ;j<m ; j++){
                if(grid[i][j] == '1' && !visited[i][j] ){
                    icelands(grid, n, m ,i ,j,visited);
                    res++;
                }
            }
        }
        return res;

    }
};