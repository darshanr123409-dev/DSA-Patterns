#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 TreeNode* ans = nullptr;
class Solution {
public:
    int lower_root(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return 0;
        }
        int left =  lower_root(root->left,p,q);
        int right =  lower_root(root->right,p,q);

        int root_lo = 0;
        if( root == p or root == q ){
            root_lo = 1;
        }

        int total = left + root_lo + right ;
        if( total == 2 && ans == nullptr ){
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        lower_root(root,p,q);
        return ans; 
    }
};
