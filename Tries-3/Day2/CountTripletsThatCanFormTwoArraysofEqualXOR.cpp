class Trie{
   public:
   Trie* children[2];
   vector<int> index;
   Trie(){
    children[0]=NULL,children[1]=NULL;
   } 
};
void insert(int a,Trie* root,int index)
{
    for(int i=31;i>=0;i--)
    {
        bool b=(a>>i)&1;
        if(root->children[b]==NULL) root->children[b]=new Trie();
        root=root->children[b];
    }
    root->index.push_back(index);
}
vector<int> query(int a,Trie* root)
{
    for(int i=31;i>=0;i--)
    {
        bool b=(a>>i)&1;
        if(root->children[b]==NULL) 
        return {};
        root=root->children[b];
    }
    return root->index;
}
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        Trie* root=new Trie();
        int xor=0,c=0; 
        insert(0,root,-1);
        for(int i=0;i<arr.size();i++)
        {
            xor=(xor^arr[i]);
            vector<int> temp=query(xor,root);
            if(temp.size()){
                for(auto x:temp){
                    c+=(i-x-1);
                }
            }
            insert(xor,root,i);
        }
        return c;
    }
};
