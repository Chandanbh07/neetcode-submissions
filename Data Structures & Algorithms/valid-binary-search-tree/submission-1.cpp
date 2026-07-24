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

    bool bst(TreeNode* root, int leftvalid , int rightvalid){
        if(root == NULL) return true;

        int lsub = bst(root->left , leftvalid , root->val);
        int rsub = bst(root->right , root->val , rightvalid);

        return lsub && rsub && (root->val > leftvalid && root->val < rightvalid);
    }
};
