class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        stack<int> st;
        int n=colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<unordered_map<int,int>> m(n);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            m[f][colors[f]-'a']++;
            for(auto j:adj[f]){
                for(auto k:m[f]){
                  m[j][k.first]=max(m[j][k.first],k.second);  
                }
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }
        for(auto j:indegree)
        if(j!=0) 
        return -1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(auto j:m[i]){
                maxi=max(maxi,j.second);
            }
        }
        return maxi;
    }
};