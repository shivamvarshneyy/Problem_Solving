class Solution {
public:
    Node* solve(Node* node, unordered_map<Node*,Node*>& m)
    {
        if(node==NULL) 
        return NULL;
        if(m.find(node)==m.end())
        {
            Node* temp=new Node(node->val);
            m[node]=temp;
            for(auto i:node->neighbors)
            {
                if(m.find(i)!=m.end()){
                (temp->neighbors).push_back(m[i]);
                }
                else{
                temp->neighbors.push_back(solve(i,m));
                }
            }
            return temp; 
        }
        return NULL;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> m;
        Node* res=solve(node,m);
        return res;
    }
};