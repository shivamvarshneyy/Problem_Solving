/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<TreeNode<int>*> rightSideView(TreeNode<int>* root) {
   vector<TreeNode<int>*> res;
   root = root->right;
   while(root!=NULL){
       if(root->left!=NULL || root->right!=NULL) res.push_back(root);
       if(root->right) root=root->right;
       else root=root->left;
   }
   return res;
}

vector<TreeNode<int>*> leftView(TreeNode<int> *root)
{
   vector<TreeNode<int>*> res;
   root = root->left;
   while(root!=NULL){
       if(root->left!=NULL || root->right!=NULL) res.push_back(root);
       if(root->left) root=root->left;
       else root=root->right;
   }
   return res;
}

void bottomView(TreeNode<int>* root,vector<TreeNode<int>*> &res) {
        if(root->left==NULL && root->right==NULL){
            res.push_back(root);
            return;
        }
        if(root->left) bottomView(root->left,res);
        if(root->right) bottomView(root->right,res);
        
    }

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if(root==NULL) return res;
    if(root->left!=NULL || root->right!=NULL) res.push_back(root->data);

    vector<TreeNode<int>*> left = leftView(root);
    vector<TreeNode<int>*> right = rightSideView(root);
    vector<TreeNode<int>*> bottom;
    bottomView(root,bottom);
    
    for(auto i:l) res.push_back(i->data);
    for(auto i:b) res.push_back(i->data);
    reverse(r.begin(),r.end());
    for(auto i:r) res.push_back(i->data);
    return res;
}