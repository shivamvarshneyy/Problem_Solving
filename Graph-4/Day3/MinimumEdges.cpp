class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int s,int e)
        {
            deque<pair<int,int>> q;
            vector<int> dis(n+1,INT_MAX);
            vector<vector<pair<int,int>>> adj(n+1);
            for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
            q.push_back({0,s});
            dis[s]=0;
            while(!q.empty()){
                int d=q.front().first;
                int node=q.front().second;
                if(node==e) 
                return d;
                q.pop_front();
                for(auto i:adj[node]){
                    if(d+i.second<dis[i.first]){
                        dis[i.first]=d+i.second;
                        if(i.second==0)
                        q.push_front({d+i.second,i.first});
                        else
                        q.push_back({d+i.second,i.first});
                    }
                }
            }
            return -1;
        }
};