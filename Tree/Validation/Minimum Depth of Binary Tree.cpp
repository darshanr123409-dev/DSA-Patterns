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
    int minDepth(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        // If left child is NULL, go right
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        // If right child is NULL, go left
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        // If both children exist
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};
