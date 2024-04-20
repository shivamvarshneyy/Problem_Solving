class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size(),n=grid[0].size();
	    vector<vector<int>> visited(m,vector<int>(n,-1));
	    queue<pair<int,int>> q;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                visited[i][j]=0;
	            }
	        }
	    }
	    int c=1;
	    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
	    while(!q.empty()){
	        int size=q.size();
	        for(int i=0;i<size;i++)
	        {
	            int x=q.front().first;
	            int y=q.front().second;
	            q.pop();
	            for(int i=0;i<4;i++){
	                int u=x+direction[i][0],v=y+direction[i][1];
	                if(u>=0 && v>=0 && u<m && v<n && visited[u][v]==-1){
	                    visited[u][v]=c;
	                    q.push({u,v});
	                }
	            }
	        }
	        c++;
	    }
	    return visited;
	}
};