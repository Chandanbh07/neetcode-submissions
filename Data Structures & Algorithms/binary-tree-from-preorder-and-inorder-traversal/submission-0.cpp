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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
        return helper( preorder , inorder , preIdx , 0 , inorder.size()-1 );
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int& preIdx , int left , int right){

        if(left > right) return NULL;

        TreeNode* node = new TreeNode(preorder[preIdx]);
        preIdx++;
        
        int inIdx = search(inorder ,node->val ,left , right);
        node->left = helper(preorder ,inorder ,preIdx ,left ,inIdx-1);
        node->right = helper(preorder ,inorder ,preIdx , inIdx+1 , right);

        return node;
    }

    int search(vector<int>& inorder , int val , int left , int right){
        for(int i=left ;i<= right ;i++){
            if(inorder[i] == val) return i;
        }
        return -1;
    }
};
