class Trie{
    public:
    int cnt;
    Trie* children[2];
    Trie(){
        cnt=0;
        for(int i=0;i<2;i++) 
        children[i]=NULL;
    }
};
void insert(int a,Trie* root)
{
    for(int i=31;i>=0;i--)
    {
        bool bit=((a>>i)&1);
        if(root->children[bit]==NULL) 
        {
            root->children[bit]=new Trie();
        }
        root=root->children[bit];
        root->cnt++;
    }
}
int query(int tmp,int a,Trie* root,int bit)
{
    if(bit==-1) return root->cnt;
    int cnt=0;
    bool bit=((a>>bit)&1);
    bool c=((tmp>>bit)&1);
    if(root->children[0]!=NULL)
    {
        if((bit^0)<c)        
        cnt+=root->children[0]->cnt;
        else if((bit^0)==c)  
        cnt+=query(tmp,a,root->children[0],bit-1);
    }
    if(root->children[1]!=NULL)
    {
        if((bit^1)<c)        
        cnt+=root->children[1]->cnt;
        else if((bit^1)==c)  
        cnt+=query(tmp,a,root->children[1],bit-1);
    }
    return cnt;
}
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int c=0;
        Trie* root=new Trie();
        for(int i=0;i<nums.size();i++)
        {
            int num1=query(high,nums[i],root,31);
            int num2=query(low-1,nums[i],root,31);
            c+=num1-num2;
            insert(nums[i],root);
        }
        return c;
    }
};