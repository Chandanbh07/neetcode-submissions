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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return height(root) != -1;
    }

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int left_Ht = height(root->left);
        if(left_Ht == -1) return -1;

        int right_Ht = height(root->right);
        if(right_Ht == -1) return -1;

        if(abs(left_Ht - right_Ht) > 1) return -1;

        return max(left_Ht, right_Ht) + 1 ;
    }
};
