/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }

    int helper(TreeNode* root, int maxsofar){
        if(root == NULL) return 0;

        int good = (root->val >= maxsofar) ? 1:0;

        maxsofar = max(root->val , maxsofar);

        return good + helper(root->left,maxsofar) + helper(root->right,maxsofar);
    }
};
