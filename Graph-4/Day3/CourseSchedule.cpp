class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& visited,vector<int>& path)
    {
        if(path[i]) 
        return 1;
        visited[i]=1;
        path[i]=1;
        for(auto j:adj[i])
        {
            if(!visited[j]) 
            {
                if(dfs(j,adj,visited,path))
                return 1;
            }
            else if(path[j]) 
            return 1; 
        }
        path[i]=0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(n,0);
        vector<int> path(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            if(dfs(i,adj,visited,path)) 
            return 0;
        }
        return 1;
    }
};