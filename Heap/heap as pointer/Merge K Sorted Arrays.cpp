#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    class Node {
        public:
      int value;
      int row;
      int col;

      Node(int v, int i, int j)
      {
          value=v;
          row=i;
          col=j;
      }
  };
  
  struct Compare {
      bool operator()(const Node &a, const Node &b) {
          return a.value > b.value;   // min heap
      }
  };
  
     vector<int> mergeArrays(vector<vector<int>> &a) {
          vector<int> res;
          int n=a.size();
          int m=a[0].size();
          priority_queue<Node, vector<Node>, Compare> pq;
          int i;
          for(i=0;i<n;i++)
          {
              pq.push({a[i][0], i,0});
          }
          while(!pq.empty())
          {
              Node n=pq.top();
              res.push_back(n.value);
              pq.pop();
              int col=n.col;
              if(col==m-1) // over
              continue;
              pq.push({a[n.row][col+1],n.row,col+1});


          }
          return res;

}
};