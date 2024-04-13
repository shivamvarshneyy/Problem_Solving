
class Trie{
    public:
    bool isEnd;
    int index;
    Trie* children[26];
    Trie(){
        isEnd=0;
        index=INT_MAX;
        for(int i=0;i<26;i++) 
        children[i]=NULL;
    }
};
void insert(int ind,string s,Trie* root,vector<string>& wordsContainer)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        if(root->children[s[i]-'a']==NULL)
        {
            root->children[s[i]-'a']=new Trie();
        }
        root=root->children[s[i]-'a'];
        if(root->index==INT_MAX || wordsContainer[root->index].size()>s.size())
         root->index=ind;
    }
    root->isEnd=1;
}
int query(string s,Trie* root)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        if(root->children[s[i]-'a']==NULL) 
        return root->index;
        root=root->children[s[i]-'a'];
    }
    return root->index;
}
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* root=new Trie();
        int ind=0,mini=INT_MAX;
        for(int i=0;i<wordsContainer.size();i++){
            insert(i,wordsContainer[i],root,wordsContainer);
            if(mini>wordsContainer[i].size()){
                mini=wordsContainer[i].size();
                ind=i;
            }
        }
        vector<int> res;
        for(int i=0;i<wordsQuery.size();i++)
        {
            res.push_back(query(wordsQuery[i],root));
            if(res[i]==INT_MAX)
            res[i]=ind;
        }
        return res;
    }
};