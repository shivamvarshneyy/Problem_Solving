class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    grid[i][j]=0;
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int cnt;
        q.size()?cnt=0:cnt=1;
        vector<vector<int>> direction={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x1=x+direction[i][0];
                    int y1=y+direction[i][1];
                    if(x1<m && y1<n && x1>=0 && y1>=0 && !visited[x1][y1] && grid[x1][y1]==1)
                    {
                        visited[x1][y1]=1;
                        grid[x1][y1]=2;
                        q.push({x1,y1});
                    }
                }
            }
            cnt++;
        }
        for(auto x:grid)
        {
            for(auto y:x)
            {
                if(y==1) 
                {
                    return -1;
                }
            }
        }
        return cnt-1;
    }
};