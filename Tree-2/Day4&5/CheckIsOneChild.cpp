bool check(vector<int> &preorder,int n){
    for(int i=1;i<n;i++)
    {
        if(preorder[i-1]>preorder[i] && preorder[i-1]<preorder[preorder.size()-1] || preorder[i-1]<preorder[i] && preorder[i-1]>preorder[preorder.size()-1]) 
        return false;
    }
    return true;
}