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
    int search(vector<int>& inorder, int root, int left, int right){
        for(int i = left; i<=right; i++){
            if(inorder[i] == root) return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left , int right){
        if(left > right) return NULL;

        TreeNode* root = new TreeNode( preorder[preIdx] );
        int rootIdx = search(inorder,preorder[preIdx],left,right);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left , rootIdx-1);
        root->right = helper(preorder, inorder, preIdx, rootIdx+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIdx=0;
        return helper(preorder,inorder,preIdx,0,n-1);
    }
};
