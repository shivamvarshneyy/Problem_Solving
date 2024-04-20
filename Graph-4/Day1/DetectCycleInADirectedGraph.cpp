class Solution {
  public:
    bool dfs(int s,vector<int> *adj,vector<int> &visited,vector<int> &path){
        visited[s]=1;
        path[s]=1;
        for(auto x:adj[s]){
            if(!visited[x]){ 
                if(dfs(x,adj,visited,path)) 
                return true;
            }
            else if(path[x]==1) return true;
        }
        path[s]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> path(V,0);
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)) return true;
            }
        }
        return false;
    }
};