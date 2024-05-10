class Solution
{
public:
    long long solve(int n,vector<int> &dp){
        if(n==0) 
        return 1;
        else if(dp[n]!=-1) 
        return dp[n];
        long long count=0;
        if(n-2>=0) count=(count+((n-1)*solve(n-2,dp))%1000000007)%1000000007;
        count=(count+solve(n-1,dp))%1000000007;
        return dp[n]=count;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i-2>=0) dp[i]=(dp[i]+((i-1)*dp[i-2])%1000000007)%1000000007;
            dp[i]=(dp[i]+dp[i-1])%1000000007;
        }
        return dp[n];
    }
};    