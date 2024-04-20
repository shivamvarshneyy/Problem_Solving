class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& boards,vector<vector<int>>& visited)
    {
        int m=boards.size();
        int n=boards[0].size();
        visited[i][j]=1;
        vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++)
        {
            int x=i+direction[k][0];
            int y=j+direction[k][1];
            if(x>=0 && y>=0 && x<m && y<n && !visited[x][y] && boards[x][y]=='O')
            dfs(x,y,boards,visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && (i==0 || j==0 || i==m-1 ||j==n-1) && board[i][j]=='O')
                {
                    dfs(i,j,board,visited);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};