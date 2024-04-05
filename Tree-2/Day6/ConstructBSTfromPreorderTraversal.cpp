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
    void insertnode(TreeNode*root, int value)
    {
        if(value<root->val)
        {
            if(root->left==NULL)
            root->left=new TreeNode(value);
            else
            insertnode(root->left, value);
        }
        else
        {
            if(root->right==NULL)
            root->right=new TreeNode(value);
            else
            insertnode(root->right, value);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode;
        root->val=preorder[0];
        for(int i=1;i<preorder.size();i++)
        {
            insertnode(root,preorder[i]);
        }
        return root;
    }
};