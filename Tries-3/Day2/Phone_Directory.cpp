class Node{
	Node* children[26];
  	bool isEnd;
  	public:
  	Node(){
    	for(int i=0;i<26;i++) 
        children[i] = NULL;
      	isEnd = false;
    }
  	void insert(string word){
    	Node* temp =this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(temp->children[word[i]-'a']==NULL){
                temp->children[word[i]-'a'] = new Node();
            }
            temp = temp->children[word[i]-'a'];
        }
      temp->isEnd = true;
    }
  	vector<string> suggestions(string word){
    	Node* temp =this;
        int n = word.length();
        string w = "";
        for(int i=0;i<n;i++){
            if(temp->children[word[i]-'a']==NULL){
                return {"0"};
            }
            w+=word[i];
            temp = temp->children[word[i]-'a'];
        }
        vector<string> arr;
        helper(w,temp,arr);
        if(arr.size()==0) arr.push_back("0");
        return arr;
    }
  	void helper(string w,Node* temp,vector<string>& arr){
    	if(temp->isEnd){
    	    arr.push_back(w);
    	}
      for(int i=0;i<26;i++){
      	if(temp->children[i]!=NULL){
          	w+=('a'+i);
        	helper(w,temp->children[i],arr);
            w.pop_back();
        }
      }
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> arr;
        Node* root = new Node();
        for(int i=0;i<n;i++){
            root->insert(contact[i]);
        }
        int n = s.length();
        for(int i=0;i<n;i++){
            arr.push_back(root->suggestions(s.substr(0,i+1)));
        }
        return arr;
    }
};