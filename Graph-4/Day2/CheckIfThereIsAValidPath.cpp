class Solution {
private:
    bool solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& v){
        int m=grid.size(),n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(i==m-1 && j==n-1) return true; 
        v[i][j]=true;
        bool End=false;
        if(grid[i][j]==1){
            if(j+1<n && !v[i][j+1] && grid[i][j+1]!=2)  End=solve(i,j+1,grid,v);
            if(j-1>=0 && !v[i][j-1] && grid[i][j-1]!=2) End=End | solve(i,j-1,grid,v);
        }
        else if(grid[i][j]==2){
            if(i-1>=0 && !v[i-1][j] && grid[i-1][j]!=1) End=solve(i-1,j,grid,v);
            if(i+1<m && !v[i+1][j] && grid[i+1][j]!=1)    End=End | solve(i+1,j,grid,v);
        }
        else if(grid[i][j]==3){
            if(i+1<m && !v[i+1][j] && (grid[i+1][j]==2 || grid[i+1][j]==6 || grid[i+1][j]==5))  End=solve(i+1,j,grid,v);
            if(j-1>=0 && !v[i][j-1] && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6)) End=End | solve(i,j-1,grid,v);
        }
        else if(grid[i][j]==4){
            if(j+1<n && !v[i][j+1] && (grid[i][j+1]==5 || grid[i][j+1]==1 || grid[i][j+1]==3))  End=solve(i,j+1,grid,v);
            if(i+1<m && !v[i+1][j] && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))  End=End | solve(i+1,j,grid,v);
        } 
        else if(grid[i][j]==5){
            if(i-1>=0 && !v[i-1][j] && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))   End=solve(i-1,j,grid,v);
            if(j-1>=0 && !v[i][j-1] && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==5)) End=End | solve(i,j-1,grid,v);
        }
        else if(grid[i][j]==6){
            if(i-1>=0 && !v[i-1][j] && (grid[i-1][j]==4 || grid[i-1][j]==3 || grid[i-1][j]==2)) End=solve(i-1,j,grid,v);
            if(j+1<n && !v[i][j+1] && (grid[i][j+1]==5 || grid[i][j+1]==3 || grid[i][j+1]==1))  End=End | solve(i,j+1,grid,v);
        }
        return End;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();       
        vector<vector<int>> v(m,vector<int>(n,0));
        return solve(0,0,grid,v);
    }
};