class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        vector<set<int>> ans(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto j:adj[f]){
                for(auto k:ans[f]){
                    ans[j].insert(k);
                }
                ans[j].insert(f);
                indegree[j]--;
                if(!indegree[j]) q.push(j);
            }
        }
        vector<vector<int>> anc(n);
        for(int i=0;i<n;i++){
            for(auto k:ans[i]){
                anc[i].push_back(k);
            }
        }
        return anc;
    }
};