class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &visited,int s){
        visited[s]=1;
        for(auto x:adj[s]){
            if(!visited[x])
            dfs(adj,visited,x);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        dfs(adj,visited,source);
        if(!visited[destination]) return false;
        return true;
    }
};