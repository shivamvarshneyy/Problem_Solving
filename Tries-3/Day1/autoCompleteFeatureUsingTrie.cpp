#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    bool isEnd;
    vector<int> index;
    Trie* children[26];
    Trie(){
        isEnd=0;
        for(int i=0;i<26;i++) 
        children[i]=NULL;
    }
};
void insert(int ind,Trie* root,string x)
{
    for(int i=0;i<x.size();i++)
    {
        if(root->children[x[i]-'a']==NULL)
        {
            root->children[x[i]-'a']=new Trie();
        }
        root=root->children[x[i]-'a'];
        root->index.push_back(ind);
    }
    root->isEnd=1;
}
vector<int> query(string x,Trie* root)
{
    for(int i=0;i<x.size();i++)
    {
        if(root->children[x[i]-'a']==NULL) return {};
        root=root->children[x[i]-'a'];
    }
    return root->index;
}
int main()
{
    
    Trie* root=new Trie();
    vector<string> words={"hello","dog","hell","cat","catman","a","hel","help","helps","helping","helpless"};
    for(int i=0;i<words.size();i++)
    {
        insert(i,root,words[i]);
    }
    string x;
    cout<<"Search:"<<endl;
    cin>>x;
    vector<int> ans=query(x,root);
    cout<<"Seggestions:"<<endl;
    for(auto x:ans) cout<<words[x]<<endl;
    return 0;
}