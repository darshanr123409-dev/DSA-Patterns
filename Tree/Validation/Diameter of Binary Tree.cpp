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
private:
    int res = 0;

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        res = max(res, left + right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        height(root);
        return res;
    }
};