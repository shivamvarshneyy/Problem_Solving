class Solution
{
	public:
	void dfs(int i,vector<vector<int>> &adj,vector<int> &visited,stack<int> & s){
	    visited[i]=1;
	    for(auto j:adj[i])
	    if(!visited[j])
	    dfs(j,adj,visited,s);
	    s.push(i);
	}
	void Edfs(int i,vector<vector<int>> &adj,vector<int> &visited){
	    visited[i]=1;
	    for(auto j:adj[i])
	    if(!visited[j])
	    Edfs(j,adj,visited);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> visited(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        vector<vector<int>> newadj(V);
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto j:adj[i]){
                newadj[j].push_back(i);
            }
        }
        int c=0;
        while(!s.empty()){
            if(!visited[s.top()]){
                c++;
                Edfs(s.top(),newadj,visited);
            }
            s.pop();
        }
        return c;
    }
};