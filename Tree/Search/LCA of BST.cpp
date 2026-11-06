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
    TreeNode* ans = nullptr;

    void find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return;
        }

        if (root == p || root == q) {
            ans = root;
            return;
        }

        if (root->val < p->val) {
            find(root->right, p, q);
        }
        else if (root->val > q->val) {
            find(root->left, p, q);
        }
        else {
            ans = root;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;

        if (p->val < q->val) {
            find(root, p, q);
        }
        else {
            find(root, q, p);
        }

        return ans;
    }
};