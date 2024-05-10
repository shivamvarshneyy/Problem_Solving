class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m - 1]=1; 
        dp[n - 1][m]=1; 
        for (int i=n-1;i>=0;i--) {
            for (int j=m-1;j>=0;j--) {
                int minimum=min(dp[i + 1][j],dp[i][j + 1]);
                dp[i][j]=max(1,minimum-grid[i][j]);
            }
        }
        return dp[0][0];
    }
};