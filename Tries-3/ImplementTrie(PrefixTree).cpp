class Trie {
class Node{
    public:
    bool isend;
    vector<Node*> children;
    Node(){
        isend=0;
        children.resize(26,NULL);
    }
};
public:
    Node* root,* temp;
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL){
                temp->children[word[i]-'a']=new Node();
            }
            temp=temp->children[word[i]-'a'];
        }
        temp->isend=true;
    }
    bool search(string word) {
        temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL) return false;
            temp=temp->children[word[i]-'a'];
        }
        if(temp->isend==true) return true;
        else return false;
    }
    bool startsWith(string prefix) {
        temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(temp->children[prefix[i]-'a']==NULL) return false;
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
};