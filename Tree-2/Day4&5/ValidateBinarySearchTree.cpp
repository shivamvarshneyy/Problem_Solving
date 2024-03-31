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
    vector<int> inorder(TreeNode* root,vector<int>& v)
    {
        if(root==NULL) return v;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);  
        return v; 
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]>=v[i])
            return false;
        }
    return true;
    }
};