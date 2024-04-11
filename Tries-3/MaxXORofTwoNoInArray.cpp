//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Trie{
    public:
    vector<Trie*> children;
    Trie(){
        children.resize(2,NULL);
    }
};
void insert(int a,Trie* root)
{
    for(int i=31;i>=0;i--)
    {
        bool b=((a>>i)&1);
        if(root->children[b]==NULL) root->children[b]=new Trie();
        root=root->children[b];
    }
}
int query(int a,Trie* root)
{
    int res=0;
    for(int i=31;i>=0;i--)
    {
        bool b=((a>>i)&1);
        if(root->children[1-b]!=NULL){
            res+=(1<<i);
            root=root->children[1-b];
        }
        else root=root->children[b];
    }
    return res;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int res=0;
        Trie* root=new Trie();
        insert(nums[0],root);
        for(int i=1;i<nums.size();i++)
        {
            res=max(res,query(nums[i],root));
            insert(nums[i],root);
        }
        return res;
    }
};