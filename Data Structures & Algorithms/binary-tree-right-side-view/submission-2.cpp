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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        return rightView(root,ans,0);
    }

    vector<int> rightView(TreeNode *root , vector<int>& ans, int level){
        if(root == NULL) return ans;

        if(ans.size() == level){
            ans.push_back(root->val);
        }

        if(root->right) rightView(root->right, ans,level+1);
        if(root->left) rightView(root->left, ans , level+1);

        return ans;
    }
};
