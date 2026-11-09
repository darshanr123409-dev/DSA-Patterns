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
    bool ans = true;
    void check(TreeNode* root){
        if(root == nullptr){
            return ;
        }
        check(root->left);
        if(root == nullptr){
            pre = root;
        }
        else{
            if(pre != nullptr && root->val <= pre->val){
                ans = false;
            }
            pre = root;
        }
        check(root->right);
    }
    bool isValidBST(TreeNode* root) {
        // bool ans = true;
        check(root);
        return ans ;
    }
};