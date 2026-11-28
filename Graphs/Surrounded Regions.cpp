#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    void dfa(vector<vector<char>>& arr, int n, int m, int i, int j) {

        arr[i][j] = '#';

        for(int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row, col, n, m) && arr[row][col] == 'O') {
                dfa(arr, n, m, row, col);
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        if(n == 0) return;

        int m = board[0].size();
        if(m == 0) return;

        // First row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                dfa(board, n, m, 0, j);
            }
        }

        // Last row
        for(int j = 0; j < m; j++) {
            if(board[n-1][j] == 'O') {
                dfa(board, n, m, n-1, j);
            }
        }

        // First column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                dfa(board, n, m, i, 0);
            }
        }

        // Last column
        for(int i = 0; i < n; i++) {
            if(board[i][m-1] == 'O') {
                dfa(board, n, m, i, m-1);
            }
        }

        // Replace characters
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};
