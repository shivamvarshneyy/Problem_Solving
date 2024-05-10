class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int j = 0; j<n; j++)
        {
            dp[m-1][j] = grid[m-1][j];
        }
        for(int i = m-1; i>= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1) 
                continue;
                int res = 1e9;
                for (int k = 0; k < n; k++) {
                    res = min(res, grid[i][j] + moveCost[grid[i][j]][k] + dp[i+1][k]);
                }
                dp[i][j] = res;
            }
        }
        return res;
    }
};