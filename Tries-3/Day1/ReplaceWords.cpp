class TrieNode{
    public:
   
    TrieNode* children[26];
    bool isEnd;
    string word;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]= NULL;
        }
        isEnd=false;
        string word="";
    }
};
class Solution {
public:
    TrieNode* root=new TrieNode();
    string replaceWords(vector<string>& dict, string sent) {
        for(int i=0;i<dict.size();i++)
        {
            insert(dict[i]);
        }
        stringstream ss(sent);
        string res;
        while(ss>>sent)
        {
            res+=(search(sent));
            res+=" ";
        }
        if(!res.empty())
        {
            res.pop_back();
        }
        return res;
        
    }
    void insert(string &s)
{
    TrieNode* node=root;
    for(int i=0;i<s.size();i++)
    {
        if(node->children[s[i]-'a']==NULL)
        {
            node->children[s[i]-'a']=new TrieNode();
        }
        node=node->children[s[i]-'a'];
    }
    node->isEnd=true;
    node->word=s;
}
string search(string sent)
{
    TrieNode* node=root;
    for(int i=0;i<sent.size();i++)
    {
        if(node->isEnd)
        {
            return node->word;
        }
        if(node->children[sent[i]-'a']==NULL)
        {
            return sent;
        }
       
          node=node->children[sent[i]-'a'];
        
    }
   return sent;
} 
};