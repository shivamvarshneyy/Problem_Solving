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
private:
    int maxHeight(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        return 1+max(maxHeight(root->left), maxHeight(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int a = maxHeight(root->left)+maxHeight(root->right);  
        int b = diameterOfBinaryTree(root->left); 
        int c = diameterOfBinaryTree(root->right);

        return max(a,max(b,c));
    }
};