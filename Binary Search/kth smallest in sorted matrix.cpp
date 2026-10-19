#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_cnt(vector<vector<int>>& arr,int n, int m, int mid){
        int row = n-1;
        int col = 0;
        int cnt =0;
        while( row>=0 && col<m){
            if(arr[row][col]<=mid){
                cnt += row + 1;
                col++;
            }
            else {
                row--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        int res =-1;
        while( low <= high ){
            int mid = (low + high)/2;
            int ans = find_cnt(matrix,n,m,mid); 
            if(ans<k){
                low = mid+1;
            }
            else {
                res = mid;
                high = mid -1;
            }
        }
        return res;
    }
};