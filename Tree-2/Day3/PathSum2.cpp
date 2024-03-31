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
    void pathSum(TreeNode* root,int targetSum,vector<int>& v,vector<vector<int>>& ans){
        if(root==NULL)return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==targetSum)
        ans.push_back(v);
        pathSum(root->left,targetSum-root->val,v,ans);
        pathSum(root->right,targetSum-root->val,v,ans);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        pathSum(root,targetSum,v,ans);
        return ans;
    }
};