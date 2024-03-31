vector<int> ans;
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                root=q.front();
                q.pop();
                v.push_back(root->data);
                if(root->left)
                q.push(root->left);
                if(root->right)
                q.push(root->right);
            }
           ans.push_back(v[0]);
        }
        return ans;