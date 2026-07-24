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
    bool isValidBST(TreeNode* root) {
      return bst(root ,INT_MIN,INT_MAX);   
    }

    bool bst(TreeNode* root, int lowBound , int highBound){
        if(root == NULL) return true;

        if(lowBound >= root->val || root->val >= highBound) return false;

        return bst(root->left , lowBound , root->val) 
               && bst(root->right , root->val , highBound);
    }
};
