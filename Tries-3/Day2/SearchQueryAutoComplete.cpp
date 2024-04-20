class Node{
	Node* children[256];
  	bool isEnd;
  	int freq;
  	public:
  	Node(){
    	for(int i=0;i<256;i++)
        children[i] = NULL;
      	isEnd = false;
      	freq = 0;
    }
  	void insert(string word,int f){
    	Node* temp =this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(temp->children[word[i]]==NULL){
                temp->children[word[i]] = new Node();
            }
            temp = temp->children[word[i]];   
        }
      temp->isEnd = true;
      temp->freq += f;
    }
  	vector<string> suggestions(string word){
    	Node* temp =this;
        int n = word.length();
        string w = "";
        for(int i=0;i<n;i++){
            if(temp->children[word[i]]==NULL){
                return {};
            }
            w+=word[i];
            temp = temp->children[word[i]];
        }
        vector<pair<string,int>> arr;
        helper(w,temp,arr);
        sort(arr.begin(),arr.end(),[&](pair<string,int>&a,pair<string,int>& b){
            return a.second==b.second?a.first<b.first:a.second>b.second;
        });
        vector<string> v;
        for(int i=0;i<min(arr.size(),3);i++){
            v.push_back(arr[i].first);
        }
        return v;
    }
  	void helper(string w,Node* temp,vector<pair<string,int>>& arr){
    	if(temp->isEnd){
    	   arr.push_back({w,temp->freq});   
    	}
      for(int i=0;i<256;i++){
      	if(temp->children[i]!=NULL){
          	w+=(char)i;
        	helper(w,temp->children[i],arr);
            w.pop_back();
        }
      }
    }
};
class AutoCompleteSystem {
    Node* root;
    string sentence;
public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Node();
        int n = sentences.size();
        for(int i=0;i<n;i++){
            root->insert(sentences[i],times[i]);
        }
    }
    vector<string> input(char c) {
        if(c=='#'){
            root->insert(sentence,1);
            sentence = "";
            return {};
        }
        sentence+=c;
        return root->suggestions(sentence);
    }
};