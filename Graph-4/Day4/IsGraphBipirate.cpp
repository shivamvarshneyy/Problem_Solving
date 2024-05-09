class Solution {
    bool dfs(vector<int>adj[], int node,vector<int>&visited){
        for(auto it: adj[node]){
            if(visited[it]==-1){
                visited[it]= !visited[node];
                if(!dfs(adj,it,visited))return false;
            }
            else if(visited[it]==vis[node])return false; 
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i] = 0;
                bool ans = dfs(adj,i,visited);
                if(!ans)return false;
            }
        }
        return true;
    }
};