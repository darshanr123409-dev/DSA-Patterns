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
    TreeNode* pre = nullptr;
    TreeNode* g1first = nullptr;
    TreeNode* g1second = nullptr;
    TreeNode* g2first = nullptr;
    TreeNode* g2second = nullptr;
    int galath = 0;

    void checks(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        checks(root->left);

        if (pre != nullptr && root->val < pre->val) {

            if (galath == 0) {
                g1first = root;
                g1second = pre;
                galath++;
            }
            else {
                g2first = root;
                g2second = pre;
                galath++;
            }
        }

        pre = root;

        checks(root->right);
    }

    void recoverTree(TreeNode* root) {
        checks(root);

        if (galath == 1) {
            swap(g1first->val, g1second->val);
        }
        else {
            swap(g1second->val, g2first->val);
        }
    }
};
