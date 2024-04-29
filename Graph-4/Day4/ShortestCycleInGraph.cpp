class Solution {
public:
    int bfs(int s,int d,vector<unordered_set<int>> &adj){
        queue<int> q;
        vector<int> visited(adj.size(),0);
        visited[s]=1;
        q.push(s);
        int l=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int f=q.front();
                q.pop();
                if(f==d) 
                return l;
                for(auto i:adj[f]){
                    if(!visited[i]){
                        visited[i]=1;
                        q.push(i);
                    }
                }
            }
            l++;
        }
        return INT_MAX;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(auto i:edges)
        {
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        int mini=INT_MAX;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0],b=edges[i][1];
            adj[a].erase(b);
            adj[b].erase(a);
            mini=min(mini,bfs(a,b,adj));
            adj[a].insert(b);
            adj[b].insert(a);
        }
        if(mini==INT_MAX) 
        return -1;
        return mini;
    }
};