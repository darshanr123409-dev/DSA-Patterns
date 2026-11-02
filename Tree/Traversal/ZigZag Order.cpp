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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        int count = 0;

        while (!q.empty()) {

            count++;

            int lvlsize = q.size();
            vector<int> temp;

            while (lvlsize--) {

                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }

            // Even level: reverse direction
            if (count % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            res.push_back(temp);
        }

        return res;
    }
};