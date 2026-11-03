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
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p== nullptr && q == nullptr ){
            return true;
        }
        if( p == nullptr or q == nullptr ){
            return false;
        }
        if( p->val !=q->val ){
            return false;
        }
        bool root1 = isSameTree(p->left,q->left);
        bool root2 = isSameTree(p->right,q->right);
        if( root1 == true and root2 == true ){
            return true;
        }
        return false ;
    }
};