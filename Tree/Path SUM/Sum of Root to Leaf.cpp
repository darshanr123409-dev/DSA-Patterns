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
    int overall_max = 0;
    void sum(TreeNode* root,int curr_sum){
        if(root == NULL){
            return;
        }
        if(curr_sum == 0){
            curr_sum += root->val;
        }
        else{
            curr_sum = (curr_sum * 10) + root->val;
        }

        if(root->left == NULL && root->right == NULL){
            overall_max += curr_sum;
            return;
        }


        sum(root->left,curr_sum);
        sum(root->right,curr_sum);
    }
    int sumNumbers(TreeNode* root) {
        sum(root,0);
        return overall_max;
    }
};
