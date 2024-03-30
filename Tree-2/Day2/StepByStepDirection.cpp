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
    TreeNode* lca(TreeNode *root, int s, int e) {
        if(!root) return NULL;
        if(root->val == s) return root;
        if(root->val == e) return root;
        auto l = lca(root->left, s, e);
        auto r = lca(root->right, s, e);
        if(l && r) return root;
        return l ? l : r;
    }
    bool getPath(TreeNode *root, int val, string &path) {
        if(!root) return false;
        if(root->val == val) return true;
        path += 'L';
        bool t = getPath(root->left, val, path);
        if(t) return true;
        path.pop_back();
        path += 'R';
        t = getPath(root->right, val, path);
        if(t) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        string p1, p2;
        getPath(root, startValue, p1);
        getPath(root, destValue, p2);
        for(auto &i : p1) i = 'U';
        return p1 + p2;
    }
};