//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeData{
  public:
  int maxNode,minNode,maxSize;
  NodeData(int minNode,int maxNode,int maxSize){
      this->minNode=minNode;
      this->maxNode=maxNode;
      this->maxSize=maxSize;
  }
};
class Solution{
    private:
    NodeData largestBST(Node* root)
    {
        if(!root)return NodeData(INT_MAX,INT_MIN,0);
        auto left=largestBST(root->left);
        auto right=largestBST(root->right);
        if(left.maxNode<root->data && root->data<right.minNode)
        {
            return NodeData(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
        }
        return NodeData(INT_MAX,INT_MIN,max(left.maxSize,right.maxSize));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return largestBST(root).maxSize;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends


//2nd METHOD-----------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    //function to check if tree is bst or not 
    bool valid(Node*root , int mini , int  maxi){
        if(root==NULL){
            return true;
        }
        if(root->data>mini && root->data<maxi){
            bool left =valid(root->left , mini, root->data );
            bool right=valid(root->right , root->data , maxi);
            return left&&right;
        }
        else{
            return false;
        }
    }
    int count(Node*root){
        if(root==NULL){
            return 0;
        }
        return 1+count(root->left)+count(root->right);
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	if(root==NULL){
    	    return 0;
    	}
    	if(valid (root, INT_MIN , INT_MAX)){
    	    return count(root);
    	}
    	int l=largestBst(root->left);
    	int r=largestBst(root->right);
    	
    	return max(l,r);
    }
};