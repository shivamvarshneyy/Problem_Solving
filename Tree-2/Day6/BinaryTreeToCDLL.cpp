class Solution
{
  public:
    Node* head=NULL,*prev=NULL;
    void inorder(Node* root)
    {
        if(!root) return;
        inorder(root->left);
        if(prev)
        {
            root->left=prev;
            prev->right=root;
            if(!head) head=prev;
        }
        prev=root;
        inorder(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
        inorder(root);
        prev->right=head;
        head->left=prev;
        return head;
    }
};