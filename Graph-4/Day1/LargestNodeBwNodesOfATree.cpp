int dfs(int s,vector<vector<int>> &adj,vector<int> &visited,int &maxdis){
    visited[s]=1;
    priority_queue<int> pq;
    int ans=0,c=2,ans=0;
    for(auto x:adj[s]){
        if(!visited[x]){
            int len=1+dfs(x,adj,visited,maxdis);
            pq.push(len);
        }
    }
    while(!pq.empty() && c){
        if(ans==0) 
        ans=pq.top(); 
        ans+=pq.top();
        pq.pop();
        c--;
    }
    maxdis=max(maxdis,ans);
    return ans;
}
int Solution::solve(vector<int> &A) {
    int ans=0,maxi=A.size();
    for(auto x:A) maxi=max(maxi,x+1);
    vector<vector<int>> adj(maxi+1);
    vector<int> visited(maxi+1);
    for(int i=0;i<A.size();i++){
        if(A[i]!=-1){
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    int maxdis=0;
    int x=dfs(0,adj,visited,maxdis);
    return maxdis;
}