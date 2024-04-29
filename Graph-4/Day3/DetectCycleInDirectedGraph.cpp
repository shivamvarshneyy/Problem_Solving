class Solution {
  public:
    bool dfs(int i,vector<int> *adj,vector<int> &visited,vector<int> &path){
        visited[i]=1;
        path[i]=1;
        for(auto x:adj[i]){
            if(!visited[x]){ 
                if(dfs(x,adj,visited,path)) 
                return true;
            }
            else if(path[x]==1) 
            return true;
        }
        path[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> path(V,0);
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)) 
                return true;
            }
        }
        return false;
    }
};