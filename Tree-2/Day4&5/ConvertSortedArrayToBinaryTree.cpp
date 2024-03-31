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
    TreeNode* construct(vector<int>& nums,int s,int e)
    {
        if(s>e){
            return nullptr;
        }
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=construct(nums,s,mid-1);
        root->right=construct(nums,mid+1,e);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};