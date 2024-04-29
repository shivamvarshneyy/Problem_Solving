class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<int> visited(n,0);
        vector<int> res;
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                q.push(i);
                visited[i]=1;
            }
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            res.push_back(t);
            for(auto j:adj[t])
            {
                if(--indegree[j]==0)
                {
                    q.push(j);
                    visited[j]=1;
                }
            }
        }
        if(res.size()==n) 
        return res;
        else              
        return {};
    }
};