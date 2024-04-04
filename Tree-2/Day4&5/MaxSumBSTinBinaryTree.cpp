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

class NodeVal{
  public:
  int maxNode; 
   int minNode;
   bool isBst;
   int sum ;
};
    NodeVal helper(TreeNode* root,int&ans)
    {
        if(!root) return {INT_MIN,INT_MAX,true,0};
        NodeVal left=helper(root->left,ans);
        NodeVal right=helper(root->right,ans);
        NodeVal node;
        node.sum = left.sum +right.sum +root->val;
        node.maxNode=max(root->val,right.maxNode);
        node.minNode=min(root->val,left.minNode);
        if(left.isBst && right.isBst && (root->val>left.maxNode && root->val<right.minNode)){
            node.isBst= true;
        }
        else{
        node.isBst = false;
        }
        if(node.isBst){
            ans = max(ans,node.sum);
        }
        return node;
    }
class Solution{
    public:
    int maxSumBST(TreeNode* root) {
        if(!root)return 0;
        int m=0;
        NodeVal obj=helper(root,m);
        return m;
    }
};