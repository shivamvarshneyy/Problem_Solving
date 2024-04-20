class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>> &grid)
    {
        visited[i][j]=1;
        vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            int x=i+direction[i][0],y=j+direction[i][1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1' && !visited[x][y]){
                dfs(x,y,visited,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
};