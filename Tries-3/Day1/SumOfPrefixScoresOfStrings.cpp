class Trie{
    public:
    int cnt;
    vector<Trie*> children;
    Trie(){
        cnt=0;
        children.resize(26,NULL);
    }
};
void insert(string &word,Trie* root)
{
    for(int i=0;i<word.size();i++)
    {
        if(root->children[word[i]-'a']==NULL){
            root->children[word[i]-'a']=new Trie();
        }
        root=root->children[word[i]-'a'];
        root->cnt++;
    }
}
int findcount(string &word,Trie* root)
{
    int c=0;
    for(int i=0;i<word.size();i++)
    {
        root=root->children[word[i]-'a'];
        c+=root->cnt;
    }
    return c;
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *t=new Trie();
        vector<int> res;
        for(int i=0;i<words.size();i++)
        {
            insert(words[i],t);
        }
        for(int i=0;i<words.size();i++){
            res.push_back(findcount(words[i],t));
        }
        return res;
    }
};